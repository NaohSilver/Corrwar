/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:01:39 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:58:42 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoind(char *s1, char *s2, int dela, int delb)
{
	char	*str;
	int		s1_len;

	if (!s1 || !s2)
		exit(-42);
	s1_len = ft_strlen(s1);
	if ((str = ft_strnew(s1_len + ft_strlen(s2))) == NULL)
		exit(-42);
	ft_strcpy(str, s1);
	ft_strcpy(str + s1_len, s2);
	if (dela && s1)
		ft_strdel(&s1);
	if (delb && s2)
		ft_strdel(&s2);
	return (str);
}
