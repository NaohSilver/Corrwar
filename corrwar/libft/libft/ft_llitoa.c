/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:21:59 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:49:05 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_llitoa(long long int n)
{
	int						neg;
	unsigned long long int	nbr;
	int						i;
	char					*str;

	neg = n < 0;
	nbr = neg ? -n : n;
	i = 1 + neg;
	while (nbr / 10 > 0)
		i++ && (nbr /= 10);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	if (neg)
		(str[0] = '-') && i--;
	nbr = neg ? -n : n;
	while (i)
	{
		i--;
		str[i + neg] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
