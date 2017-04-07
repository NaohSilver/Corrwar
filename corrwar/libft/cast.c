/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:33:13 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/15 21:51:59 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>
#include <wchar.h>

t_dcap		cast_d(t_argf *arg, va_list ap)
{
	if (arg->length == L_T || arg->type == 'D')
		return (va_arg(ap, signed long));
	else if (arg->length == HH_T)
		return ((signed char)va_arg(ap, int));
	else if (arg->length == H_T)
		return ((signed short)va_arg(ap, int));
	else if (arg->length == LL_T)
		return (va_arg(ap, signed long long));
	else if (arg->length == J_T)
		return (va_arg(ap, intmax_t));
	else if (arg->length == Z_T)
		return (va_arg(ap, size_t));
	return (va_arg(ap, int));
}

t_udcap		cast_ud(t_argf *arg, va_list ap)
{
	if (arg->length == L_T || ft_strchr("UO", arg->type))
		return (va_arg(ap, unsigned long));
	else if (arg->length == HH_T)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (arg->length == H_T)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (arg->length == LL_T)
		return (va_arg(ap, unsigned long long));
	else if (arg->length == J_T)
		return (va_arg(ap, uintmax_t));
	else if (arg->length == Z_T)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

char		*cast_s(t_argf *arg, va_list ap)
{
	wchar_t	*ss;
	char	*s;
	char	*s2;

	if (arg->type == 'S' || arg->length == L_T)
	{
		if (!(ss = va_arg(ap, wchar_t *)))
			return (NULL);
		if (!(s = ft_wcstombs(ss, arg->precision)))
			arg->type = -1;
		return (s);
	}
	s2 = va_arg(ap, char *);
	if (s2 == NULL)
		s2 = ft_strdup("(null)");
	return (s2);
}

int			cast_c(t_argf *arg, va_list ap)
{
	if (arg->type == 'C' || arg->length == L_T)
		return (va_arg(ap, wint_t));
	return ((signed char)va_arg(ap, int));
}
