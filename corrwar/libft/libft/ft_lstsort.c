/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 06:46:50 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/09 06:57:25 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lstsort_lex(t_list *a, t_list *b)
{
	return (ft_strcmp((char *)(a->content), (char *)(b->content)));
}

int		lstsort_desclex(t_list *a, t_list *b)
{
	return (ft_strcmp((char *)(b->content), (char *)(a->content)));
}

int		lstsort_asc(t_list *a, t_list *b)
{
	return (*(int *)(b->content) - *(int *)(a->content));
}

int		lstsort_desc(t_list *a, t_list *b)
{
	return (*(int *)(a->content) - *(int *)(b->content));
}

t_list	*ft_lstsort(t_list *to_sort, int (*f)(t_list *a, t_list *b))
{
	t_list	*sorted;
	t_list	*elem;
	t_list	*tmp[2];
	int		i;

	sorted = to_sort;
	elem = to_sort->next;
	to_sort->next = NULL;
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
