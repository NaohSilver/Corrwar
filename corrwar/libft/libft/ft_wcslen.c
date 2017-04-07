/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:46:38 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:02:19 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslen(const int *wcs)
{
	int	n;

	n = 0;
	while (*wcs != L'\0')
	{
		n += ft_wcscbytes(ft_binsize(*wcs));
		wcs++;
	}
	return (n);
}
