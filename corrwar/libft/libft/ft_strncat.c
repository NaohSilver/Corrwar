/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:47:48 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/10 16:22:23 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*c1;
	char	*c2;

	c1 = s1;
	c2 = (char *)s2;
	while (*c1)
		c1++;
	while (n-- && *c2)
		*c1++ = *c2++;
	*c1 = '\0';
	return (s1);
}
