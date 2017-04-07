/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:21:33 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:49:28 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_llitob(long long int n)
{
	int		len;
	char	*res;

	len = !n ? 1 : ft_binsize(n);
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	len--;
	while (n && len >= 0)
	{
		res[len--] = (n & 1) + '0';
		n = n >> 1;
	}
	return (res);
}
