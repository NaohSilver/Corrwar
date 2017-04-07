/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdupom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:52:02 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:01:20 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabstrdupom(char **tab)
{
	char	**final;
	int		i;

	if (!tab)
		return (NULL);
	i = 0;
	final = ft_memalloc(sizeof(char *) * (ft_tabcnt(tab) + 2));
	while (tab[i])
	{
		final[i] = ft_strdup(tab[i]);
		if (!final[i])
			return (NULL);
		i++;
	}
	return (final);
}
