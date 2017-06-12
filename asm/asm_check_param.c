/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:11:49 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:25:30 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_is_reg(char *param)
{
	if (param[0] == 'r')
	{
		if (ft_strisint(param + 1))
		{
			if (ft_atoi(param + 1) >= 0 && ft_atoi(param + 1) <= 99)
				return (1);
		}
	}
	return (0);
}

int		ft_is_ind(t_list *labels, char *param)
{
	int				i;
	t_list			*elem;
	t_label			*tmp;

	i = 0;
	if (param[i] == '-')
		i++;
	if (param[i] == '\0')
		return (0);
	if (param[i] == LABEL_CHAR)
	{
		elem = labels;
		while (elem)
		{
			tmp = elem->content;
			if (!ft_strncmp(param + 1, tmp->label, ft_strlen(tmp->label) - 1))
				return (1);
			elem = elem->next;
		}
		return (0);
	}
	while (param[i])
		if (!ft_isdigit(param[i++]))
			return (0);
	return (1);
}

int		ft_is_dir(t_list *labels, char *param)
{
	unsigned int	i;

	i = 0;
	if (param[i] == DIRECT_CHAR)
		return (ft_is_ind(labels, param + i + 1));
	return (0);
}

int		ft_validate_param(t_list *labels, char *ins, int p_type, int i)
{
	int		flag;

	flag = 0;
	if (p_type & T_REG)
		if (ft_is_reg(ins))
			flag = 1;
	if (p_type & T_DIR)
		if (ft_is_dir(labels, ins))
			flag = 1;
	if (p_type & T_IND)
		if (ft_is_ind(labels, ins))
			flag = 1;
	if (!flag)
		return (0);
	return (i + ft_strlen(ins));
}

int		ft_parse_params(t_list *labels, char *f_content, int i, int idx)
{
	char	*ins;
	int		nb_instr;

	nb_instr = -1;
	while (++nb_instr < g_op_tab[idx].nb_param)
	{
		while (ft_iswhitespace(f_content[i]))
			i++;
		if (f_content[i] == ',')
			i++;
		while (ft_iswhitespace(f_content[i]))
			i++;
		if ((ins = ft_strsub(f_content, i,
				ft_get_param_end(f_content, i) - i)) == NULL)
			return (0);
		if (!(i = ft_validate_param(labels, ins,
			g_op_tab[idx].param[nb_instr], i)))
		{
			free(ins);
			return (0);
		}
		free(ins);
	}
	return (i);
}
