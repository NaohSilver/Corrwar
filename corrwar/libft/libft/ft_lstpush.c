/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:18:36 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:52:16 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpush(t_list *alst, t_list *new)
{
	t_list	*elem;

	elem = alst;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
	return (alst);
}
