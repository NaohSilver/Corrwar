/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:23:00 by niludwig          #+#    #+#             */
/*   Updated: 2017/04/07 02:00:31 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	new->next = NULL;
	if (!(*alst))
		*alst = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r')
		return (1);
	else
		return (0);
}

char		*ft_strjoin_and_free(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (str);
}

static long	ft_atoi_oflow(char *str)
{
	int		i;
	int		sign;
	long	ans;

	i = 0;
	sign = 1;
	ans = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' && ++i)
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ans * 10 + (str[i] - '0') >= 0)
			ans = 10 * ans + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	return (ans * sign);
}

static int			ft_strccpy(char *dst, char *src, char c)
{
	size_t i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

static int		ft_jump_nextline(char *str, int i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

t_list	*ft_init_label(char *label)
{
	t_list		*new;
	t_label		*tmp;

	if (label == NULL)
		return (NULL);
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((tmp = (t_label*)malloc(sizeof(t_label))) == NULL)
		return (NULL);
	tmp->label = label;
	tmp->addr = -1;
	new->content = tmp;
	new->next = NULL;
	return (new);
}

int		ft_save_label(t_tasm *tasm, int i, int j)
{
	t_list	*new;
	char	*label;

	if (tasm->f_content[i] == LABEL_CHAR)
	{
		if ((label = ft_strsub(tasm->f_content, j, i + 1 - j)) == NULL)
			return (0);
		if ((new = ft_init_label(label)) == NULL)
			return (0);
		ft_lstaddtail(&tasm->labels, new);//le mien
	}
	return (1);
}

int		ft_get_labels(t_tasm *tasm)
{
	char	*f_content;
	int		i;
	int		j;

	f_content = tasm->f_content;
	i = tasm->idx;
	while (f_content[i])
	{
		if (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
			i = ft_jump_nextline(f_content, i);
		if (ft_strchr(LABEL_CHARS, f_content[i]))
		{
			j = i;
			while (ft_strchr(LABEL_CHARS, f_content[i]))
				i++;
			if (!ft_save_label(tasm, i, j))
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_get_param_end(char *f_content, int i)
{
	while (f_content[i] != SEPARATOR_CHAR && !ft_iswhitespace(f_content[i])
		&& f_content[i] && f_content[i] != COMMENT_CHAR && f_content[i] != ';')
		i++;
	return (i);
}

int		asm_parse_body(t_tasm *tasm)
{
	if (!ft_get_labels(tasm))
		return (0);
	if (!ft_check_body(tasm->labels, tasm->f_content, tasm->idx))
		return (0);
	return (1);
}

int		ft_skip_spaces(char *line)
{
	int i;

	i = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	return (i);
}

int		ft_get_param_value(char *f_content, char *curr_param, int i,
								unsigned int max_size)
{
	unsigned int tmp;

	i += ft_skip_spaces(f_content + i);
	if (f_content[i] == '\"')
	{
		i++;
		tmp = ft_strccpy(curr_param, f_content + i, '\"');
		if (tmp > max_size)
			return (0);
		i += tmp;
	}
	if (!f_content[i])
		return (0);
	return (i + 1);
}

int		ft_handle_hlabel(t_tasm *tasm, char *f_content
									, int i, char *parse_state)
{
	char			*curr_param;
	unsigned int	max_size;

	if (!ft_strncmp(f_content + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		*parse_state |= 2;
		curr_param = tasm->prog_name;
		max_size = PROG_NAME_LENGTH;
		i += ft_strlen(NAME_CMD_STRING);
	}
	else
	{
		*parse_state |= 1;
		curr_param = tasm->comment;
		max_size = COMMENT_LENGTH;
		i += ft_strlen(COMMENT_CMD_STRING);
	}
	return (ft_get_param_value(f_content, curr_param, i, max_size));
}

int		ft_check_name_n_comm(t_tasm *tasm, int i, int state)
{
	if (!ft_strncmp(tasm->f_content + i, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)))
	{
		if (!CHECK_BIT(state, 1))
			return (1);
		else
			return (0);
	}
	else if (!ft_strncmp(tasm->f_content + i, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)))
	{
		if (!CHECK_BIT(state, 0))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		asm_parse_header(t_tasm *tasm)
{
	char	*f_content;
	int		i;
	int		tmp;
	char	parse_state;

	i = 0;
	tmp = 0;
	parse_state = 0;
	f_content = tasm->f_content;
	while (parse_state != 3)
	{
		i += ft_skip_spaces(f_content + i);
		tmp = i;
		if ((f_content[i] == COMMENT_CHAR) || (f_content[i] == ';'))
			while (f_content[tmp] && f_content[tmp] != '\n')
				tmp++;
		else if (!ft_check_name_n_comm(tasm, i, parse_state))
			return (0);
		else if (!(tmp = ft_handle_hlabel(tasm, f_content, i, &parse_state)))
			return (0);
		i = tmp;
	}
	tasm->idx = i;
	return (1);
}

char		*get_file_content(char *file_name)
{
	char	*file_content;
	char	*buffer;
	int		fd;

	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &buffer) > 0)
	{
		file_content = ft_strjoin_and_free(file_content, buffer);
		file_content = ft_strjoin_and_free(file_content, "\n");
		free(buffer);
	}
	close(fd);
	return (file_content);
}

void		exit_msg(char *str)
{
	ft_putstr_fd(str , 2);
	exit (0);
}

char		*get_file_name(char *path)
{

	int		i;
	char	*dot_cor;

	i = ft_strlen(path) + 2;
	if ((dot_cor = (char*)malloc(sizeof(char) + (i + 1))) == NULL)
		return (NULL);
	ft_strncpy(dot_cor, path, i - 3);
	ft_strcpy(dot_cor + i - 4, ".cor");
	dot_cor[i] = '\0';
	return (dot_cor);
}

int 		creat_point_cor(t_tasm *tasm, char *path, int i)
{
	char 	*dot_cor;

	if ((dot_cor = get_file_name(path)) == NULL)
		return (0);
	if ((tasm->fd = open(dot_cor, O_CREAT | O_WRONLY | O_TRUNC, 0755)) == -1)
		return (0);
	free(dot_cor);
	(void)i;
	/*
		manque la suite
	*/
	return (1);
}

int main(int ac, char **av)
{
	t_tasm	*tasm;
	int 	i;

	if (!(tasm = (t_tasm*)malloc(sizeof(t_tasm))))
		exit_msg("ERROR: Malloc failed\n");
	if (!(tasm->f_content = get_file_content(av[ac - 1])))
		exit_msg(ft_strjoin("ERROR: Can't read source file", av[ac - 1]));
	tasm->labels = NULL;
	tasm->labdirs = NULL;
	if (!(i = asm_parse_header(tasm)))
		exit_msg("ERROR: Error in header\n");
	i = tasm->idx;
	if (!(asm_parse_body(tasm)))
		exit_msg("ERROR: Error in body\n");
	if (!creat_point_cor(tasm, av[ac - 1], i))
		exit_msg("ERROR: Can't create the .cor file\n");
	ft_printf("Writing output program to %.*s.cor\n",
					ft_strlen(av[ac - 1]) - 2, av[ac - 1]);
	return (1);
}
