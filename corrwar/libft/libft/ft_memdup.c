/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 06:46:25 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/09 06:48:33 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *buffer, size_t len)
{
	void *cpy;

	if (!(cpy = ft_memalloc(len)))
		return (NULL);
	ft_memcpy(cpy, buffer, len);
	return (cpy);
}
