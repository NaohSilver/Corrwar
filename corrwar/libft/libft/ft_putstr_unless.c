/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_unless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:10:16 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:54:10 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_unless(const char *format, char *c)
{
	int	n;

	if (!c)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	n = c - format;
	if (!format || n < 0)
		return (0);
	while (n-- && format[n])
		;
	if (n == -1 && *format)
	{
		n = c - format;
		write(1, format, n);
	}
	else
	{
		ft_putstr(format);
		n = ft_strlen(format);
	}
	return (n);
}
