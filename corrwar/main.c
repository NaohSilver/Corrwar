/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:23:00 by niludwig          #+#    #+#             */
/*   Updated: 2017/04/14 01:35:28 by niludwig         ###   ########.fr       */
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

static int		ft_return(char *int_min, char *int_max, int ret)
{
	free(int_min);
	free(int_max);
	return (ret);
}

static int		ft_strisint(char *nbr)
{
	int		i;
	char	*int_min;
	char	*int_max;

	i = -1;
	int_min = ft_itoa(INT_MIN);
	int_max = ft_itoa(INT_MAX);
	if ((nbr[0] != '-' && ft_strlen(nbr) < ft_strlen(int_max)) ||
		(nbr[0] == '-' && ft_strlen(nbr) < ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 1));
	else if ((nbr[0] != '-' && ft_strlen(nbr) > ft_strlen(int_max)) ||
			(nbr[0] == '-' && ft_strlen(nbr) > ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 0));
	if (nbr[0] == '-' && ++i + 1)
		while (nbr[++i] != '\0')
			if (nbr[i] > int_min[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[0] != '-')
		while (nbr[++i] != '\0')
			if (nbr[i] > int_max[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[i] == '\0')
		return (ft_return(int_min, int_max, 1));
	return (ft_return(int_min, int_max, 0));
}

int		ft_is_reg(char *param)
{
	if (param[0] == 'r')
	{
		if (ft_strisint(param + 1))
		{
			if (ft_atoi(param + 1) >= 0 && ft_atoi(param + 1) <= 99)
				return (1);
		}
	}
	return (0);
}

int		ft_is_ind(t_list *labels, char *param)
{
	int				i;
	t_list			*elem;
	t_label			*tmp;

	i = 0;
	if (param[i] == '-')
		i++;
	if (param[i] == '\0')
		return (0);
	if (param[i] == LABEL_CHAR)
	{
		elem = labels;
		while (elem)
		{
			tmp = elem->content;
			if (!ft_strncmp(param + 1, tmp->label, ft_strlen(tmp->label) - 1))
				return (1);
			elem = elem->next;
		}
		return (0);
	}
	while (param[i])
		if (!ft_isdigit(param[i++]))
			return (0);
	return (1);
}

int		ft_is_dir(t_list *labels, char *param)
{
	unsigned int	i;

	i = 0;
	if (param[i] == DIRECT_CHAR)
		return (ft_is_ind(labels, param + i + 1));
	return (0);
}

int		ft_validate_param(t_list *labels, char *ins, int p_type, int i)
{
	int		flag;

	flag = 0;
	if (p_type & T_REG)
		if (ft_is_reg(ins))
			flag = 1;
	if (p_type & T_DIR)
		if (ft_is_dir(labels, ins))
			flag = 1;
	if (p_type & T_IND)
		if (ft_is_ind(labels, ins))
			flag = 1;
	if (!flag)
		return (0);
	return (i + ft_strlen(ins));
}

int		ft_parse_params(t_list *labels, char *f_content, int i, int idx)
{
	char	*ins;
	int		nb_instr;

	nb_instr = -1;
	while (++nb_instr < g_op_tab[idx].nb_param)
	{
		while (ft_iswhitespace(f_content[i]))
			i++;
		if (f_content[i] == ',')
			i++;
		while (ft_iswhitespace(f_content[i]))
			i++;
		if ((ins = ft_strsub(f_content, i,
				ft_get_param_end(f_content, i) - i)) == NULL)
			return (0);
		if (!(i = ft_validate_param(labels, ins,
			g_op_tab[idx].param[nb_instr], i)))
		{
			free(ins);
			return (0);
		}
		free(ins);
	}
	return (i);
}

int		ft_get_instr_len(char *f_content)
{
	int i;

	i = 0;
	while (!ft_iswhitespace(f_content[i]) && f_content[i] != DIRECT_CHAR
			&& f_content[i])
		i++;
	return (i);
}

int		ft_check_instr(t_list *labels, char *f_content, int i)
{
	int idx;
	int j;
	int label_size;

	idx = 0;
	j = 0;
	label_size = 0;
	if (!f_content[i])
		return (i);
	while (g_op_tab[idx].name)
	{
		label_size = ft_get_instr_len(f_content + i);
		if (!(ft_strncmp(f_content + i, g_op_tab[idx].name, label_size)))
		{
			i += ft_strlen(g_op_tab[idx].name);
			break ;
		}
		idx++;
	}
	if (idx == 16)
		return (0);
	if (!(i = ft_parse_params(labels, f_content, i, idx)))
		return (0);
	return (i);
}

int		ft_is_label(char *f_content, int i)
{
	int x;

	x = i;
	while (ft_iswhitespace(f_content[x]))
		x++;
	while (ft_strchr(LABEL_CHARS, f_content[x]))
		x++;
	if (f_content[x] == LABEL_CHAR)
		return (ft_is_label(f_content, x + 1));
	return (i);
}

int		ft_check_body(t_list *labels, char *f_content, int i)
{
	if (!(f_content + i + 1))
		return (0);
	while (f_content[i])
	{
		if (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
		{
			i = ft_jump_nextline(f_content, i);
			continue;
		}
		if (!ft_iswhitespace(f_content[i]))
		{
			i = ft_is_label(f_content, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			while (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
				i = ft_jump_nextline(f_content, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			if (!(i = ft_check_instr(labels, f_content, i)))
				return (0);
		}
		else
			i++;
	}
	return (1);
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
		ft_lstaddtail(&tasm->labels, new);
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

void	ft_print_header(t_tasm *tasm)
{
	int		len;

	len = ft_strlen(tasm->prog_name);
	ft_putstr_fd(tasm->prog_name, tasm->fd);
	while (++len <= PROG_NAME_LENGTH)
		write(tasm->fd, "\0", 1);
	write(tasm->fd, "\0\0\0\0\0\0\0\0", 8);
	len = ft_strlen(tasm->comment);
	ft_putstr_fd(tasm->comment, tasm->fd);
	while (++len <= COMMENT_LENGTH + 4)
		write(tasm->fd, "\0", 1);
}

void	ft_print_magic(int fd)
{
	int		magic[4];
	int		mag;
	int		i;

	i = -1;
	mag = COREWAR_EXEC_MAGIC;
	while (++i < 4)
	{
		magic[i] = (unsigned char)mag;
		mag >>= 8;
	}
	while (--i >= 0)
		ft_putchar_fd(magic[i], fd);
}

int		ft_get_param(t_tasm *tasm, t_inst *ins)
{
	int		flag;
	int		p_type;

	flag = 0;
	p_type = g_op_tab[ins->i_instr].param[ins->nb_instr];
	if (p_type & T_REG)
		ins->ocp |= ft_get_reg(ins);
	if (p_type & T_DIR)
	{
		flag = ins->ocp;
		if (*(ins->ins) == DIRECT_CHAR)
			ins->ocp |= ft_get_ind(tasm, ins, 0b10);
		flag = flag != ins->ocp ? 1 : 0;
	}
	if (!flag && p_type & T_IND)
		ins->ocp |= ft_get_ind(tasm, ins, 0b11);
	return (tasm->idx + ft_strlen(ins->ins));
}

int		ft_print_params(t_tasm *tasm, t_inst *ins, int i)
{
	char	*f_content;

	if (g_op_tab[ins->i_instr].ocp)
		ins->octet++;
	ins->nb_instr = -1;
	ins->ocp = 0;
	tasm->idx = i;
	f_content = tasm->f_content;
	while (++ins->nb_instr < g_op_tab[ins->i_instr].nb_param)
	{
		while (ft_iswhitespace(f_content[tasm->idx]))
			tasm->idx++;
		if (f_content[tasm->idx] == SEPARATOR_CHAR)
			tasm->idx++;
		while (ft_iswhitespace(f_content[tasm->idx]))
			tasm->idx++;
		if ((ins->ins = ft_strsub(f_content, tasm->idx,
				ft_get_param_end(f_content, tasm->idx) - tasm->idx)) == NULL)
			return (0);
		tasm->idx = ft_get_param(tasm, ins);
		free(ins->ins);
	}
	ft_print_param(tasm, ins);
	return (tasm->idx);
}

int		ft_get_instr(t_tasm *tasm, int i, t_inst *ins)
{
	char	*f_content;
	int		idx;
	int		label_size;

	idx = 0;
	f_content = tasm->f_content;
	label_size = 0;
	if (!f_content[i])
		return (i);
	while (g_op_tab[idx].name)
	{
		label_size = ft_get_instr_len(f_content + i);
		if (!(ft_strncmp(f_content + i, g_op_tab[idx].name, label_size)))
		{
			i += ft_strlen(g_op_tab[idx].name);
			break ;
		}
		idx++;
	}
	ins->octet += ft_putchar_fd(idx + 1, tasm->fd);
	ins->ins_octet = ins->octet;
	ins->i_instr = idx;
	if (!(i = ft_print_params(tasm, ins, i)))
		return (0);
	return (i);
}

int		ft_get_label_pos(t_tasm *tasm, t_inst *ins, int i)
{
	t_list		*tmp;
	t_label		*content;
	int			x;

	tmp = tasm->labels;
	while (ft_iswhitespace(tasm->f_content[i]))
		i++;
	while (tmp)
	{
		content = tmp->content;
		x = ft_strlen(content->label);
		if (!ft_strncmp(content->label, tasm->f_content + i, x))
		{
			if (tasm->f_content[i + x - 1] != LABEL_CHAR)
				return (i);
			content->addr = ins->octet + 1;
			return (ft_get_label_pos(tasm, ins, x + i));
		}
		tmp = tmp->next;
	}
	return (i);
}

void	ft_print_body(t_tasm *tasm, char *f_content, int i)
{
	t_inst	ins;

	ins.octet = 0;
	while (f_content[i])
	{
		if ((f_content[i] == COMMENT_CHAR || f_content[i] == ';')
			&& (i = ft_jump_nextline(f_content, i)))
			continue;
		if (!ft_iswhitespace(f_content[i]))
		{
			i = ft_get_label_pos(tasm, &ins, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			while (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
				i = ft_jump_nextline(f_content, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			if (!(i = ft_get_instr(tasm, i, &ins)))
				return ;
		}
		else
			i++;
	}
	tasm->prog_size = ins.octet;
}

void	print_label_addr(t_tasm *tasm, t_labdir *labdir)
{
	t_list	*tmp;
	t_label	*label;
	int		val;

	tmp = tasm->labels;
	while (tmp)
	{
		label = tmp->content;
		if (!ft_strcmp(labdir->label, label->label))
		{
			val = label->addr - labdir->instr_addr;
			ft_putchar_fd(val >> 8, tasm->fd);
			ft_putchar_fd(val, tasm->fd);
			if (lseek(tasm->fd, -(labdir->addr + 1), SEEK_CUR) == -1)
				return ;
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_complete_file(t_tasm *tasm)
{
	t_list		*tmp;
	t_labdir	*content;

	if (lseek(tasm->fd, PROG_NAME_LENGTH + 8, SEEK_SET) == -1)
		return ;
	ft_putchar_fd((unsigned)tasm->prog_size >> 24, tasm->fd);
	ft_putchar_fd((unsigned)tasm->prog_size >> 16, tasm->fd);
	ft_putchar_fd((unsigned)tasm->prog_size >> 8, tasm->fd);
	ft_putchar_fd((unsigned)tasm->prog_size, tasm->fd);
	if (lseek(tasm->fd, COMMENT_LENGTH + 4, SEEK_CUR) == -1)
		return ;
	tmp = tasm->labdirs;
	while (tmp)
	{
		content = tmp->content;
		if (lseek(tasm->fd, content->addr - 1, SEEK_CUR) == -1)
			return ;
		print_label_addr(tasm, content);
		tmp = tmp->next;
	}
}

int 		creat_point_cor(t_tasm *tasm, char *path, int i)
{
	char 	*dot_cor;

	if ((dot_cor = get_file_name(path)) == NULL)
		return (0);
	if ((tasm->fd = open(dot_cor, O_CREAT | O_WRONLY | O_TRUNC, 0755)) == -1)
		return (0);
	free(dot_cor);
	ft_print_magic(tasm->fd);
	ft_print_header(tasm);
	ft_print_body(tasm, tasm->f_content, i);
	ft_complete_file(tasm);
	return (1);
}

int main(int ac, char **av)
{
	t_tasm	*tasm;
	int 	i;

	if (!(tasm = (t_tasm*)malloc(sizeof(t_tasm))))
		exit_msg("ERROR: Malloc failed\n");
	if (!(tasm->f_content = get_file_content(av[ac - 1])))// recupere le fd et le nom du .cor
		exit_msg(ft_strjoin("ERROR: Can't read source file", av[ac - 1]));
	tasm->labels = NULL;// init les list
	tasm->labdirs = NULL;
	if (!(i = asm_parse_header(tasm)))// recupe et check si le nom et le comment sont au format
		exit_msg("ERROR: Error in header\n");
	i = tasm->idx;// recupere l index
	if (!(asm_parse_body(tasm)))// check si les commande sont valide
		exit_msg("ERROR: Error in body\n");
	if (!creat_point_cor(tasm, av[ac - 1], i))//creation du .cor
		exit_msg("ERROR: Can't create the .cor file\n");
	ft_printf("Writing output program to %.*s.cor\n",
					ft_strlen(av[ac - 1]) - 2, av[ac - 1]);
	return (1);
}
