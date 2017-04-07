/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:20:43 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:17:23 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_llstsort(t_list *or, long int (*f)(t_list *a, t_list *b))
{
	t_list		*sorted;
	t_list		*elem;
	t_list		*tmp[2];
	long int	i;

	sorted = or;
	elem = or->next;
	or->next = NULL;
	while (elem && (tmp[1] = sorted))
	{
		tmp[0] = elem->next;
		elem->next = NULL;
		if (f(elem, tmp[1]) <= 0 && (sorted = elem))
			elem->next = tmp[1];
		else if ((i = 1))
		{
			while (tmp[1]->next && (i = f(elem, tmp[1]->next)) > 0)
				tmp[1] = tmp[1]->next;
			if (i <= 0)
				elem->next = tmp[1]->next;
			tmp[1]->next = elem;
		}
		elem = tmp[0];
	}
	return (sorted);
}
