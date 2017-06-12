/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:14:25 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 21:05:05 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_exit_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

long	ft_atoi_oflow(char *str)
{
	int		i;
	int		sign;
	long	ans;

	i = 0;
	sign = 1;
	ans = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' && ++i)
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ans * 10 + (str[i] - '0') >= 0)
			ans = 10 * ans + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	return (ans * sign);
}

int		ft_jump_nextline(char *str, int i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int			ft_strccpy(char *dst, char *src, char c)
{
	size_t i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

void		ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
	else if (alst)
		*alst = new;
}
