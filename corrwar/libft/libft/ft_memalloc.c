/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 00:30:42 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/08 09:42:14 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*str;

	str = (void *)malloc(size);
	if (!str)
		return (NULL);
	ft_bzero((void *)str, size);
	return ((void *)str);
}
