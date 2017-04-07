/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 04:52:57 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 18:42:41 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	int		c;
	char	*str;

	a = 0;
	c = 0;
	if (!(s))
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[a] != '\0')
		a++;
	b = a;
	a--;
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && a >= 0)
	{
		c++;
		a--;
	}
	str = (char *)malloc(sizeof(char) * (b - c) + 1);
	if (str == NULL)
		return (NULL);
	str[b - c] = '\0';
	return (ft_strncpy(str, s, b - c));
}
