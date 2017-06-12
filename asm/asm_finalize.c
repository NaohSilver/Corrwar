/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_finalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:12:25 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:34:52 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_ocp_return(t_inst *ins, int oc)
{
	if (ins->nb_instr == 0)
		return (oc << 6);
	else if (ins->nb_instr == 1)
		return (oc << 4);
	else
		return (oc << 2);
}

char	*get_file_name(char *path)
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

int		asm_finalize(char *path, t_asm *asmb, int i)
{
	char	*dot_cor;

	if ((dot_cor = get_file_name(path)) == NULL)
		return (0);
	if ((asmb->fd = open(dot_cor, O_CREAT | O_WRONLY | O_TRUNC, 0755)) == -1)
		return (0);
	free(dot_cor);
	ft_print_magic(asmb->fd);
	ft_print_header(asmb);
	ft_print_body(asmb, asmb->f_content, i);
	ft_complete_file(asmb);
	return (1);
}
