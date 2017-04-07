/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 04:42:48 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/07 17:14:30 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*sorc = src;
	size_t				i;

	i = 0;
	dest = dst;
	if (src < dst)
	{
		while (len--)
			dest[len] = sorc[len];
	}
	else
	{
		while (i < len)
		{
			dest[i] = sorc[i];
			i++;
		}
	}
	return (dst);
}
