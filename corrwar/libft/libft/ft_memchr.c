/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:01:42 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 01:08:53 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cp;

	i = 0;
	cp = (unsigned char *)s;
	while (i < n)
	{
		if (cp[i] == (unsigned char)c)
			return ((void*)&cp[i]);
		i++;
	}
	return (NULL);
}
