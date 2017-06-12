/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:10:26 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 19:20:25 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_asm		*asmb;
	int			i;

	if (!(asmb = (t_asm*)malloc(sizeof(t_asm))))
		ft_exit_msg("Error in malloc");
	if (!(asmb->f_content = ft_get_file_content(av[ac - 1])))
		ft_exit_msg(ft_strjoin("Can't read source file ", av[ac - 1]));
	asmb->labels = NULL;
	asmb->labdirs = NULL;
	if (!(i = asm_parse_header(asmb)))
		ft_exit_msg("Error in header");
	i = asmb->idx;
	if (!asm_parse_body(asmb))
		ft_exit_msg("Error in body");
	if (!asm_finalize(av[ac - 1], asmb, i))
		ft_exit_msg("Can't create the .cor file");
	ft_printf("Writing output program to %.*s.cor\n",
					ft_strlen(av[ac - 1]) - 2, av[ac - 1]);
	return (1);
}
