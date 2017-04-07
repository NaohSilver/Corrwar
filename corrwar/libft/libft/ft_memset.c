/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:13:13 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/10 22:01:10 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *bi;

	bi = (unsigned char *)b;
	while (len--)
	{
		*bi = (unsigned char)c;
		if (len)
			bi++;
	}
	return (b);
}
