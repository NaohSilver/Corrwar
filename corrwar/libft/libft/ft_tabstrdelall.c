/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdelall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:54:07 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:00:00 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabstrdelall(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}
