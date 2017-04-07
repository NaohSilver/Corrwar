/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:25:49 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 08:17:30 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	i;
	unsigned int	len;
	char			*new;

	if (!(s) || !(f))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (NULL);
	if (!(new = ft_memalloc(len + 1)))
		return (NULL);
	index = 0;
	while (i < len && s[i])
	{
		new[i] = f(index++, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
