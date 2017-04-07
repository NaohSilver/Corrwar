/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:49:59 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:01:57 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_ullitoa(unsigned long long int n)
{
	unsigned long long int	nbr;
	int						i;
	char					*str;

	i = 1;
	nbr = n;
	while (nbr / 10 > 0)
		i++ && (nbr /= 10);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	nbr = n;
	while (i)
	{
		i--;
		str[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
