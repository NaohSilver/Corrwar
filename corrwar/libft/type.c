/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:33:58 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:38:01 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *g_octalbase = "01234567";
char *g_uhexbase = "0123456789ABCDEF";
char *g_lhexbase = "0123456789abcdef";

int			types_d(t_argf *arg, va_list ap)
{
	char	*s;
	int		n;

	if (arg->type == 'b')
	{
		if (!(s = ft_llitob(cast_ud(arg, ap))))
			return (-1);
		arg->flag[FL_MORE] = FALSE;
		arg->flag[FL_SPCE] = FALSE;
	}
	else if (ft_strchr("uU", arg->type))
	{
		if (!(s = ft_ullitoa(cast_ud(arg, ap))))
			return (-1);
		arg->flag[FL_MORE] = FALSE;
		arg->flag[FL_SPCE] = FALSE;
	}
	else if (!(s = ft_llitoa(cast_d(arg, ap))))
		return (-1);
	if (*s == '0' && arg->precision == 0)
		*s = 0;
	n = print_integer(arg, s);
	free(s);
	return (n);
}

int			types_x(t_argf *arg, va_list ap)
{
	char	*s;
	int		sl;
	char	*base;

	base = arg->type == 'X' ? g_uhexbase : NULL;
	base = arg->type == 'x' ? g_lhexbase : base;
	base = base ? base : g_octalbase;
	if (!(s = ft_ullitoa_base(cast_ud(arg, ap), base)))
		return (-1);
	if ((*s == '0' || !*s) && arg->precision == 0)
		*s = 0;
	if (arg->flag[FL_HASH])
	{
		if (ft_strchr("oO", arg->type)
				&& arg->precision <= (sl = (int)ft_strlen(s))
				&& *s != '0')
			arg->precision = sl + 1;
		else if (ft_strchr("xX", arg->type) && *s != '0' && *s)
			arg->oxfl = arg->type == 'x' ? 1 : 2;
	}
	arg->flag[FL_MORE] = FALSE;
	arg->flag[FL_SPCE] = FALSE;
	sl = print_integer(arg, s);
	free(s);
	return (sl);
}

int			types_s(t_argf *arg, va_list ap)
{
	int		n;
	char	*ss;
	char	*c;

	ss = cast_s(arg, ap);
	if (arg->type == -1)
		return (-1);
	if (arg->flag[FL_LESS])
		arg->flag[FL_ZERO] = FALSE;
	n = arg->precision > -1 ? arg->precision : STRLENNULL(ss);
	if ((c = (char *)ft_memchr(ss, 0, n)))
		n = c - ss;
	arg->width = arg->width > n ? arg->width - n : 0;
	n = print_string(ss, arg, FALSE);
	if ((arg->type == 'S' || arg->length == L_T) && ss)
		free(ss);
	return (n);
}

int			types_c(t_argf *arg, va_list ap)
{
	wchar_t	s[2];
	char	*ss;
	int		n;

	s[0] = cast_c(arg, ap);
	s[1] = L'\0';
	if (s[0] < 0)
	{
		if (!(ss = ft_strnew(2)))
			return (-1);
		ss[0] = s[0];
	}
	else if (!(ss = ft_wcstombs(s, -1)))
		return (-1);
	n = *s ? ft_strlen(ss) : 1;
	arg->precision = -1;
	arg->width = arg->width > n ? arg->width - n : 0;
	n = print_string(ss, arg, !*s);
	free(ss);
	return (n);
}

int			types_p(t_argf *arg, va_list ap)
{
	t_udcap	p;
	char	*s;
	int		n;

	p = (t_udcap)va_arg(ap, void *);
	if (!(s = ft_ullitoa_base(p, g_lhexbase)))
		return (-1);
	if (*s == '0' && arg->precision == 0)
		*s = 0;
	arg->oxfl = 1;
	arg->flag[FL_MORE] = FALSE;
	arg->flag[FL_SPCE] = FALSE;
	n = print_integer(arg, s);
	free(s);
	return (n);
}
