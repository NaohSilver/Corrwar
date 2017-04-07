/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 03:52:59 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 09:59:57 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				i;
	unsigned int	n;
	int				signe;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\n')
		i++;
	signe = (str[i] == '-') ? -signe : signe;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] && str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return (((int)n) * signe);
}
