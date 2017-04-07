/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 05:31:12 by niludwig          #+#    #+#             */
/*   Updated: 2016/11/14 05:37:14 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if ((lst)->next == NULL)
		f(lst);
	else
	{
		ft_lstiter(lst->next, f);
		f(lst);
	}
}
