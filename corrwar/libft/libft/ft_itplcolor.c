/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itpcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 02:22:47 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:47:57 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_itplcolor(int a, int b, double step)
{
	unsigned char	rgb[3];

	rgb[0] = ft_interpolate((a >> 16) & 255, (b >> 16) & 255, step);
	rgb[1] = ft_interpolate((a >> 8) & 255, (b >> 8) & 255, step);
	rgb[2] = ft_interpolate(a & 255, b & 255, step);
	return (ft_rgb(rgb[0], rgb[1], rgb[2]));
}
