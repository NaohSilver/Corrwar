/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:36:16 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 08:01:40 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s1) \
		+ ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		new[i + i2] = s2[i2];
		i2++;
	}
	new[i + i2] = '\0';
	return (new);
}
