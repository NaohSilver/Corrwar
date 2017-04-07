/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:13:41 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 08:03:06 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	i2;
	char	*new;

	i = start;
	i2 = 0;
	if (!(s))
		return (NULL);
	if (!(new = ft_memalloc(len + 1)))
		return (0);
	while (i2 != len)
	{
		new[i2] = s[i];
		i++;
		i2++;
	}
	new[i] = '\0';
	return (new);
}
