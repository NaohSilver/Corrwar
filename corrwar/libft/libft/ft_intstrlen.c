/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:24:35 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:46:41 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intstrlen(int i)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_itoa(i);
	if (!tmp)
		return (0);
	else
		j = ft_strlen(tmp);
	free(tmp);
	return (j);
}
