/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdelx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:53:18 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:00:16 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabstrdelx(char **tab, int i)
{
	int	c;

	c = 0;
	while (c != i)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}
