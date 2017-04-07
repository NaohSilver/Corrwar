/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 06:46:13 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/09 06:51:19 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstchr(t_list *lst, void *chr,
				t_bool (*cmp)(void *elem, void *chr, int size))
{
	while (lst)
	{
		if (cmp(lst->content, chr, lst->content_size))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
