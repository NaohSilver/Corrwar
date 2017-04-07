/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:08:03 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/15 22:42:23 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putxchar(char c, int l)
{
	char	*s;

	if (!l || !(s = ft_memalloc(l)))
		return ;
	ft_memset(s, (int)c, l);
	write(1, s, l);
	free(s);
}
