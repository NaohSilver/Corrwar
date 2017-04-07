/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 03:10:30 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 07:10:31 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((unsigned char)*s1 == (unsigned char)*s2 && n--)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	if (!n)
		return (((unsigned char)*--s1 - (unsigned char)*--s2));
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
