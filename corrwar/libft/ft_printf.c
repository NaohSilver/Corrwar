/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:33:30 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:28:11 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_argf	*default_arg(t_argf *arg)
{
	int			i;

	i = 0;
	while (i < 5)
		arg->flag[i++] = FALSE;
	arg->width = -1;
	arg->precision = -1;
	arg->length = -1;
	arg->type = -1;
	arg->func_type = NULL;
	arg->end = NULL;
	arg->oxfl = 0;
	return (arg);
}

static char		*parse_arg(char *s, t_argf *arg, va_list ap)
{
	int			n;
	int			f;

	s++;
	f = 0;
	while (*s && f < 5)
	{
		n = -1;
		if (f < 1 && (n = find_arg_flag(s, arg)) > -1)
			;
		else if (f < 2 && (n = find_arg_wp(s, arg, FALSE, ap)) > -1)
			;
		else if (f < 3 && (n = find_arg_wp(s, arg, TRUE, ap)) > -1)
			;
		else if (f < 4 && (n = find_arg_length(s, arg)) > -1)
			;
		else if ((n = find_arg_type(s, arg)) > -1 && (s += n))
			break ;
		else
			break ;
		if (n > -1)
			s += n;
	}
	return (s);
}

static int		print_arg(const char *format, va_list ap, t_argf *arg)
{
	arg->end = parse_arg((char *)format, default_arg(arg), ap);
	if (arg->type == -1 && *(arg->end))
		return (notype(arg));
	return (arg->func_type ? arg->func_type(arg, ap) : 0);
}

static int		no_percent(const char **format, int *i)
{
	char		*p;
	char		*c;

	if (**format == '{')
	{
		*format = color((char *)(*format + 1), i);
		return (0);
	}
	p = ft_strchr(*format, '%');
	c = ft_strchr(*format, '{');
	p = !p || (c && c < p) ? c : p;
	if (p)
	{
		ft_putstr_until(*format, p);
		*i += p - *format;
		*format = p;
	}
	else
	{
		ft_putstr(*format);
		*i += ft_strlen(*format);
		return (1);
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_argf		arg;
	int			i;

	va_start(ap, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (format[1] == '%' && (format += 2) && ++i)
				ft_putchar('%');
			else
			{
				if ((arg.i = print_arg(format, ap, &arg)) < 0)
					return (-1);
				i += arg.i;
				format = arg.end;
			}
		}
		else if (no_percent(&format, &i))
			break ;
	}
	va_end(ap);
	return (i);
}
