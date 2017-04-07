/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 05:46:40 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 01:57:29 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int		i;
	int		nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return ((n < 0) ? i + 1 : i);
}

char		*ft_itoa(int n)
{
	int		val;
	int		len;
	char	*tmp;

	val = n;
	len = ft_nbrlen(n);
	if (&ft_nbrlen == 0)
		return (0);
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		tmp[len] = (n < 0) ? (n % 10) * -1 + 48 : (n % 10) + 48;
		n /= 10;
	}
	if (val < 0)
		tmp[0] = '-';
	return (tmp);
}
