/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:52:37 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:00:54 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabstrdup(char **tab)
{
	char	**final;
	int		i;

	if (!tab)
		return (NULL);
	i = 0;
	final = ft_memalloc(sizeof(char *) * (ft_tabcnt(tab) + 1));
	while (tab[i])
	{
		final[i] = ft_strdup(tab[i]);
		if (!final[i])
			return (NULL);
		i++;
	}
	return (final);
}
