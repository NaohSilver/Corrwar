/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:27:27 by niludwig          #+#    #+#             */
/*   Updated: 2017/04/07 01:58:51 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft/libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"
# include "op.h"

typedef struct	s_tasm
{
	int			fd;
	char		*line;
	char		*content;
	char		prog_name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
}				t_tasm;

char			*get_file_content(char *file_name);
char			*ft_strjoin_n_free(char *s1, char *s2);
void			exit_msg(char *str);
int				creat_point_cor(t_asm *tasm, char *path);
char			*get_file_name(char *path);
void			asm_parse(t_tasm *tasm);//A FAIR PARSING DANS LE FICHIER
void			print_files(t_tasm *tasm);//A FAIR ECRIRE DANS LE FICHIER
#endif
