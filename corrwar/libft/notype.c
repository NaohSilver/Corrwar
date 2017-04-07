/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notype.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:33:41 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:04:31 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			notype(t_argf *arg)
{
	char	s[2];

	s[0] = *(arg->end);
	s[1] = 0;
	arg->end++;
	arg->flag[FL_SPCE] = FALSE;
	arg->precision = -1;
	return (print_integer(arg, s));
}
