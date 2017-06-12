/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:14:08 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:35:34 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_header(t_asm *asmb)
{
	int		len;

	len = ft_strlen(asmb->prog_name);
	ft_printf("%s%@", asmb->prog_name, asmb->fd);
	while (++len <= PROG_NAME_LENGTH)
		write(asmb->fd, "\0", 1);
	write(asmb->fd, "\0\0\0\0\0\0\0\0", 8);
	len = ft_strlen(asmb->comment);
	ft_printf("%s%@", asmb->comment, asmb->fd);
	while (++len <= COMMENT_LENGTH + 4)
		write(asmb->fd, "\0", 1);
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
		ft_printf("%c%@", magic[i], fd);
}
