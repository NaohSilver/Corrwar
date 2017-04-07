/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcscbytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:49:13 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/15 22:24:31 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wcscbytes(int binsize)
{
	if (binsize <= 7)
		return (1);
	if (binsize <= 11)
		return (2);
	if (binsize <= 16)
		return (3);
	return (4);
}
