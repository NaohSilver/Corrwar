/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:04:30 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:57:28 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	int	color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}
