/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_nc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:19:35 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:51:49 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew_nc(void *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	ft_bzero(elem, sizeof(t_list));
	if (content)
	{
		elem->content = content;
		elem->content_size = content_size;
	}
	return (elem);
}
