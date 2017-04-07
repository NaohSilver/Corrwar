/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:09:19 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:53:45 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_until(const char *format, char *c)
{
	if (!format)
		return ;
	write(1, format, c > format ? c - format : 0);
}
