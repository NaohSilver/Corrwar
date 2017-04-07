/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:09:52 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/16 00:12:00 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
		return (0);
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
		return (0);
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
