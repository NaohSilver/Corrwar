/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:33:51 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:34:44 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		calculate_chars(t_argf *arg, t_print_i *d, char *s)
{
	d->l = ft_strlen(s);
	if (arg->precision > -1 || arg->flag[FL_LESS])
		arg->flag[FL_ZERO] = FALSE;
	if ((arg->flag[FL_MORE] || arg->flag[FL_SPCE]) && *s != '-')
		d->l++;
	d->w = arg->width > d->l && arg->width > arg->precision;
	d->pl = arg->precision - d->l + (SIGN_FLAG(arg) || *s == '-');
	d->wl = arg->width - MAXV(arg->precision, d->l) -
		((SIGN_FLAG(arg) || *s == '-') && d->pl > 0) - (arg->oxfl ? 2 : 0);
	d->wl = d->wl < 0 ? 0 : d->wl;
	d->l += arg->oxfl ? 2 : 0;
}

static void		print_sign(t_argf *arg, char *s)
{
	if (*s == '-')
		ft_putchar('-');
	else if (arg->flag[FL_MORE])
		ft_putchar('+');
	else if (arg->flag[FL_SPCE])
		ft_putchar(' ');
}

int				print_integer(t_argf *arg, char *s)
{
	t_print_i	d;

	calculate_chars(arg, &d, s);
	if (arg->oxfl && arg->flag[FL_ZERO])
		ft_putstr(arg->oxfl == 1 ? "0x" : "0X");
	if (arg->flag[FL_ZERO])
		print_sign(arg, s);
	if (!(arg->flag[FL_LESS]) && d.w)
		ft_putxchar(arg->flag[FL_ZERO] ? '0' : ' ', d.wl);
	if (!arg->flag[FL_ZERO])
		print_sign(arg, s);
	if (arg->oxfl && !(arg->flag[FL_ZERO]))
		ft_putstr(arg->oxfl == 1 ? "0x" : "0X");
	if (*s == '-')
		s++;
	ft_putxchar('0', d.pl);
	ft_putstr(s);
	if (arg->flag[FL_LESS] && d.w)
		ft_putxchar(' ', d.wl);
	if (d.w)
		d.l += d.wl;
	return (d.l + (d.pl > 0 ? d.pl : 0));
}

int				print_string(char *s, t_argf *arg, t_bool pnchar)
{
	char		*end;
	static char	snull[] = "(null)";
	int			n;

	end = NULL;
	n = 0;
	if (!s)
		s = snull;
	if (arg->width && !(arg->flag[FL_LESS]))
		ft_putxchar(arg->flag[FL_ZERO] ? '0' : ' ', arg->width);
	if (arg->precision > -1)
		end = s + arg->precision;
	if (s && arg->precision)
		n = ft_putstr_unless(s, end);
	if (pnchar && (n = 1))
		ft_putchar(0);
	if (arg->width && arg->flag[FL_LESS])
		ft_putxchar(arg->flag[FL_ZERO] ? '0' : ' ', arg->width);
	return (n + arg->width);
}
