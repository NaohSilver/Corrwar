/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:47:18 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 18:03:59 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_wcstombs(const int *wcs, long int len)
{
	char	*s;
	int		j;
	int		i;

	if (len < 0)
		len = (long int)ft_wcslen(wcs);
	if (!(s = ft_strnew(len)))
		return (NULL);
	j = 0;
	while (j < len && *wcs != L'\0')
	{
		i = ft_wcscbytes(ft_binsize(*wcs));
		if (j + i > len)
			break ;
		ft_wctomb(s + j, *wcs, i);
		j += i;
		wcs++;
	}
	s[j] = 0;
	return (s);
}
