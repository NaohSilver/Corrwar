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

# include <fcntl.h>
# include "libft/libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"
# include "op.h"

typedef struct	s_label
{
	char		*label;
	int			addr;
}				t_label;

typedef struct	s_labdir
{
	char		*label;
	int			instr_addr;
	int			addr;
}				t_labdir;

typedef struct	s_inst
{
	char		*ins;
	int			i_instr;
	int			nb_instr;
	int			ocp;
	int			param[3];
	int			ins_octet;
	int			octet;
}				t_inst;

typedef struct	s_tasm
{
	t_list		*labels;
	t_list		*labdirs;
	int			fd;
	char		*f_content;
	char		prog_name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	int			prog_size;
	int			idx;
}				t_tasm;

/*
	print maigc print body print header et complet file
*/

t_list			*ft_init_label(char *label);
int				ft_save_label(t_tasm *tasm, int i, int j);
int				ft_get_labels(t_tasm *tasm);
int				ft_get_param_end(char *f_content, int i);
int				ft_skip_spaces(char *line);
int				ft_get_param_value(char *f_content, char *curr_param, int i,
								unsigned int max_size);
int				ft_handle_hlabel(t_tasm *tasm, char *f_content
									, int i, char *parse_state);
int				ft_check_name_n_comm(t_tasm *tasm, int i, int state);
int				asm_parse_header(t_tasm *tasm);
char			*get_file_content(char *file_name);
char			*ft_strjoin_and_free(char *s1, char *s2);
void			exit_msg(char *str);
int				creat_point_cor(t_tasm *tasm, char *path, int i);
char			*get_file_name(char *path);
int 			asm_parse_body(t_tasm *tasm);
#endif
