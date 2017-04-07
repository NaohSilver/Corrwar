/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 05:38:05 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/20 00:31:46 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*again;

	if ((lst)->next == NULL)
		return (ft_memcpy((t_list *)malloc(sizeof(t_list)), f(lst), \
			sizeof(t_list)));
	else
	{
		again = ft_memcpy((t_list *)malloc(sizeof(t_list)), f(lst), \
			sizeof(t_list));
		again->next = ft_lstmap(lst->next, f);
		return (again);
	}
}
