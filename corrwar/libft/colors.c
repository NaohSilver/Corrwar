/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:33:21 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:23:24 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*g_esccolors[9] = {
	"black",
	"red",
	"green",
	"yellow",
	"blue",
	"magenta",
	"cyan",
	"white",
	"eoc"
};

static int	find_color(char *c)
{
	char	*b;
	int		i;

	i = 0;
	while (i < 9 && !(b = NULL))
	{
		if ((b = ft_strstr(c, g_esccolors[i++])) && b == c)
			break ;
	}
	if (b)
		return (i - 1);
	return (-1);
}

static char	*no_color(char *c, int *i)
{
	ft_putchar('{');
	*i += 1;
	return (c);
}

static void	putcolor(int fg, int bg)
{
	ft_putstr(ESC_COL);
	if (fg == 8)
		ft_putchar('0');
	else
		ft_putnbr(30 + fg);
	if (bg != -1 && bg != 8 && fg != 8)
	{
		ft_putchar(';');
		ft_putnbr(40 + bg);
	}
	ft_putchar('m');
}

char		*color(char *c, int *i)
{
	char	*b;
	char	*b2;
	int		j;
	int		k[2];

	k[1] = -1;
	if ((k[0] = find_color(c)) == -1)
		return (no_color(c, i));
	b = g_esccolors[k[0]];
	j = ft_strlen(b);
	if (((j = ft_strlen(b)) && (c[j] != '}' && c[j] != ':')))
		return (no_color(c, i));
	if (c[j] == ':')
	{
		j++;
		if ((k[1] = find_color(c + j)) == -1)
			return (no_color(c, i));
		b2 = g_esccolors[k[1]];
		if ((j += ft_strlen(b2)) && c[j] != '}')
			return (no_color(c, i));
	}
	putcolor(k[0], k[1]);
	return (c + j + 1);
}
