/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:31:18 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 00:30:52 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t i2;

	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		i2 = 0;
		while (s1[i + i2] && i + i2 < n && s2[i2] && s1[i + i2] == s2[i2])
			i2++;
		if (s2[i2] == '\0')
			return ((char *)(s1 + i));
		i++;
	}
	return (0);
}
