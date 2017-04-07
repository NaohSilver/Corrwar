/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:16:59 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/07 13:23:20 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t b;

	b = 0;
	while (b < n)
	{
		*((unsigned char *)dst + b) = *((unsigned char *)src + b);
		if (*((unsigned char *)src + b) == (unsigned char)c)
			return ((unsigned char *)dst + b + 1);
		b++;
	}
	return (NULL);
}
