/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxintstrlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:15:18 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:52:55 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_maxintstrlen(int *i, int nbrofelem)
{
	char	*tmp;
	int		max;
	int		j;

	max = 0;
	j = 0;
	while (j <= (nbrofelem - 1))
	{
		tmp = ft_itoa(i[j]);
		if (!tmp)
			return (0);
		else
		{
			if (max < (int)ft_strlen(tmp))
				max = ft_strlen(tmp);
		}
		free(tmp);
		j++;
	}
	return (max);
}
