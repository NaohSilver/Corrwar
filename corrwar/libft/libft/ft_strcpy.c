/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:10:40 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 01:06:13 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *res;

	res = (char *)dst;
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (res);
}
