/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:32:54 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:18:15 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_typef		g_ptypefunctions[] = {
	{"dDiuU", &types_d},
	{"oOxX", &types_x},
	{"cC", &types_c},
	{"p", &types_p},
	{"sS", &types_s},
	{"b", &types_d},
	{NULL, NULL}
};

char		*g_flags_str = "#0- +";
char		*g_length_str = "hljz";

int			find_arg_flag(char *s, t_argf *arg)
{
	char	*n;

	if ((n = ft_strchr(g_flags_str, (int)(*s))))
		arg->flag[n - g_flags_str] = TRUE;
	return (n ? 1 : -1);
}

int			find_arg_wp(char *s, t_argf *arg, t_bool pres, va_list ap)
{
	char	*b;
	int		*field;
	int		val;

	b = s;
	field = !pres ? &(arg->width) : &(arg->precision);
	if ((*s == '*' && !pres) || (*s == '.' && s[1] == '*' && pres))
	{
		val = va_arg(ap, int);
		if (val < 0 && !pres && (val = -val))
			arg->flag[FL_LESS] = TRUE;
		return (((*field = val) || 1) && *s == '.' ? 2 : 1);
	}
	if (pres && (*s != '.' || (s++ && 0)))
		return (-1);
	if (pres && (!ft_isdigit(*s) && !(*field = 0)))
		return (1);
	if (ft_isdigit(*s))
	{
		*field = ft_atoi(s);
		while (ft_isdigit(*s))
			s++;
		return (s - b);
	}
	return (-1);
}

int			find_arg_length(char *s, t_argf *arg)
{
	char	*c;
	int		r;

	if ((s[0] == 'h' && s[1] == 'h')
	|| (s[0] == 'l' && s[1] == 'l'))
	{
		r = (*s == 'h' ? HH_T : LL_T);
		if (r > arg->length)
			arg->length = r;
		return (2);
	}
	else if ((c = ft_strchr(g_length_str, (int)(*s))))
	{
		r = c - g_length_str + (*c == 'h' || *c == 'l' ? 1 : 2);
		if (r > arg->length)
			arg->length = r;
		return (1);
	}
	return (-1);
}

int			find_arg_type(char *s, t_argf *arg)
{
	t_typef	*functions;
	char	*c;

	functions = g_ptypefunctions;
	while (functions[0].type)
	{
		if ((c = ft_strchr(functions[0].type, (int)(*s))))
		{
			arg->type = (int)(*c);
			arg->func_type = functions[0].func;
			return (1);
		}
		functions++;
	}
	return (-1);
}
