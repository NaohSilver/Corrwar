/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 01:40:02 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/11 17:31:38 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# define HH_T 0
# define H_T 1
# define L_T 2
# define LL_T 3
# define J_T 4
# define Z_T 5
# define FL_HASH 0
# define FL_ZERO 1
# define FL_LESS 2
# define FL_SPCE 3
# define FL_MORE 4
# define ESC_COL "\x1B["
# define SIGN_FLAG(ARG)(ARG->flag[FL_MORE] || ARG->flag[FL_SPCE])
# define STRLENNULL(ss)(ss ? ft_strlen(ss) : 6)

typedef int						t_bool;
typedef signed long long int	t_dcap;
typedef unsigned long long int	t_udcap;

typedef struct	s_print_i
{
	int			l;
	t_bool		w;
	int			wl;
	int			pl;
}				t_print_i;

typedef struct	s_argf
{
	int			i;
	t_bool		flag[5];
	int			width;
	int			precision;
	int			length;
	int			type;
	int			(*func_type)(struct s_argf *arg, va_list ap);
	char		*end;
	int			oxfl;
}				t_argf;

typedef struct	s_typef
{
	char		*type;
	int			(*func)(t_argf *arg, va_list ap);
}				t_typef;

int				print_integer(t_argf *arg, char *s);
int				print_string(char *s, t_argf *arg, t_bool pnchar);
int				notype(t_argf *arg);
int				ft_printf(const char *format, ...);
char			*color(char *c, int *i);
t_dcap			cast_d(t_argf *arg, va_list ap);
t_udcap			cast_ud(t_argf *arg, va_list ap);
char			*cast_s(t_argf *arg, va_list ap);
int				cast_c(t_argf *arg, va_list ap);
int				find_arg_flag(char *s, t_argf *arg);
int				find_arg_wp(char *s, t_argf *arg, t_bool pres, va_list ap);
int				find_arg_length(char *s, t_argf *arg);
int				find_arg_type(char *s, t_argf *arg);
t_argf			*parse_args(const char *format);
int				types_d(t_argf *arg, va_list ap);
int				types_x(t_argf *arg, va_list ap);
int				types_s(t_argf *arg, va_list ap);
int				types_c(t_argf *arg, va_list ap);
int				types_p(t_argf *arg, va_list ap);

#endif
