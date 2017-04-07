/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:40:44 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 08:05:43 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	len;
	char			*new;

	if (!(s) || !(f))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(new = ft_memalloc(len + 1)))
		return (NULL);
	while (i < len && s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
