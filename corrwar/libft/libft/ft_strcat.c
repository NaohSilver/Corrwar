/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:12:07 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/08 01:45:36 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*c1;
	char	*c2;

	c1 = s1;
	c2 = (char *)s2;
	while (*c1)
		c1++;
	while (*c2)
	{
		*c1 = *c2;
		c1++;
		c2++;
	}
	*c1 = '\0';
	return (s1);
}
