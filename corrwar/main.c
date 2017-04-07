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

void asm_parse(t_tasm *tasm)
{
	ft_printf("%s\n", tasm->line);
}

void		print_files(t_tasm *tasm)
{
	ft_printf("%s\n", tasm->line);
}

char		*ft_strjoin_n_free(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (str);
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

int 		creat_point_cor(t_asm *tasm, char *path)
{
	char 	*dot_cor;

	if ((dot_cor = get_file_name(path)) == NULL)
		return (0);
	if ((tasm->fd = open(dot_cor, O_CREAT | O_WRONLY | O_TRUNC, 0755)) == -1)
		return (0);
	free(dot_cor);
	print_files(tasm);
	return (1);
}

int main(int ac, char **av)
{
	t_tasm	*tasm;

	if (tasm = (t_tasm*)malloc(sizeof(t_tasm)) == NULL)
		exit_msg("ERROR: Malloc failed\n");
	if (tasm->content = get_file_content(av[ac - 1])))
		exit_msg(ft_strjoin("ERROR: Can't read source file", av[ac - 1]));
	if (!asm_parse(tasm))
		exit_msg("ERROR: Error in files\n");
	if (creat_point_cor(tasm, av[ac - 1]) == 1)
		exit_msg("ERROR: Can't create the .cor file\n");
	ft_printf("Writing output program to %.*s.cor\n",
					ft_strlen(av[ac - 1]) - 2, av[ac - 1]);
	return (0);
}
