/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_complete_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:12:10 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 20:50:12 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_label_addr(t_asm *asmb, t_labdir *labdir)
{
	t_list	*tmp;
	t_label	*label;
	int		val;

	tmp = asmb->labels;
	while (tmp)
	{
		label = tmp->content;
		if (!ft_strcmp(labdir->label, label->label))
		{
			val = label->addr - labdir->instr_addr;
			ft_putchar_fd_two(val >> 8, val, asmb->fd);
			if (lseek(asmb->fd, -(labdir->addr + 1), SEEK_CUR) == -1)
				return ;
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_complete_file(t_asm *asmb)
{
	t_list		*tmp;
	t_labdir	*content;

	if (lseek(asmb->fd, PROG_NAME_LENGTH + 8, SEEK_SET) == -1)
		return ;
	ft_putchar_fd_qutro((unsigned)asmb->prog_size >> 24,
		asmb->prog_size >> 16, asmb->prog_size >> 8, asmb->prog_size, asmb->fd);
	if (lseek(asmb->fd, COMMENT_LENGTH + 4, SEEK_CUR) == -1)
		return ;
	tmp = asmb->labdirs;
	while (tmp)
	{
		content = tmp->content;
		if (lseek(asmb->fd, content->addr - 1, SEEK_CUR) == -1)
			return ;
		print_label_addr(asmb, content);
		tmp = tmp->next;
	}
}
