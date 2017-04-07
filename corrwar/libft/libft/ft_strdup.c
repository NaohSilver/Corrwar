/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:32:30 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/10 14:29:52 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strdup(const char *s1)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	ft_strcpy(dest, s1);
	return (dest);
}
