/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:14:35 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:53:24 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_memadd(void *b1, void *b2, size_t l1, size_t l2)
{
	char	*final;
	char	*bf1;
	char	*bf2;
	size_t	i;

	bf1 = (char *)b1;
	bf2 = (char *)b2;
	i = -1;
	if (!(final = ft_memalloc(l1 + l2)))
		return (NULL);
	while (++i < l1)
		final[i] = bf1[i];
	while (l2--)
		final[l1 + l2] = bf2[l2];
	return (final);
}
