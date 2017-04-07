/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:05:19 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:58:09 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void **buffer, size_t buff_size, size_t new_size)
{
	char	*new;
	char	*old;
	size_t	i;

	old = (char *)(*buffer);
	if (!(new = ft_memalloc(new_size)))
		return (NULL);
	ft_bzero(new, new_size);
	i = 0;
	if (*buffer)
	{
		while (i < buff_size && i < new_size)
		{
			new[i] = old[i];
			i++;
		}
		free(*buffer);
	}
	return ((*buffer = (void *)new));
}
