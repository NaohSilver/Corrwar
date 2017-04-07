/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:54:48 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:59:36 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabstrdel(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}
