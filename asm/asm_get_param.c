/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:12:38 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:35:06 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_param(t_asm *asmb, t_inst *ins)
{
	int		i;

	i = -1;
	if (g_op_tab[ins->i_instr].ocp)
		ft_printf("%c%@", ins->ocp, asmb->fd);
	while (++i < ins->nb_instr)
	{
		if (((unsigned)ins->ocp >> (6 - i * 2) & 0b11) == 0b01)
			ft_printf("%c%@", ins->param[i], asmb->fd);
		else if (((unsigned)ins->ocp >> (6 - i * 2) & 0b11) == 0b11
				|| g_op_tab[ins->i_instr].label_size)
			ft_printf("%c%c%@", (unsigned)ins->param[i] >> 8,
									ins->param[i], asmb->fd);
		else
			ft_printf("%c%c%c%c%@", (unsigned)ins->param[i] >> 24,
				ins->param[i] >> 16, ins->param[i] >> 8, ins->param[i],
				asmb->fd);
	}
}

int		ft_get_labdir_pos(t_asm *asmb, t_inst *ins, t_label *tmp, int oc)
{
	t_list		*new;
	t_labdir	*content;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (0);
	if ((content = (t_labdir*)malloc(sizeof(t_labdir))) == NULL)
		return (0);
	content->label = tmp->label;
	content->instr_addr = ins->ins_octet;
	content->addr = ins->octet + 1;
	new->content = content;
	new->next = NULL;
	ins->param[ins->nb_instr] = 0;
	ft_lstaddtail(&asmb->labdirs, new);
	if (oc == 0b10)
	{
		if (g_op_tab[ins->i_instr].label_size)
			ins->octet += 2;
		else
			ins->octet += 4;
	}
	else
		ins->octet += 2;
	return (get_ocp_return(ins, oc));
}

int		ft_get_label(t_asm *asmb, t_inst *ins, int oc, int i)
{
	t_list		*elem;
	t_label		*tmp;
	int			idx;

	elem = asmb->labels;
	while (elem)
	{
		tmp = elem->content;
		idx = ft_strlen(ins->ins + i + 1) > ft_strlen(tmp->label) - 1 ?
			ft_strlen(ins->ins + i + 1) : ft_strlen(tmp->label) - 1;
		if (!ft_strncmp(ins->ins + i + 1, tmp->label, idx))
			return (ft_get_labdir_pos(asmb, ins, tmp, oc));
		elem = elem->next;
	}
	return (0);
}

int		ft_get_reg(t_inst *ins)
{
	if (ins->ins[0] == 'r')
	{
		ins->param[ins->nb_instr] = ft_atoi_oflow(ins->ins + 1);
		ins->octet++;
		return (get_ocp_return(ins, 0b01));
	}
	return (0);
}

int		ft_get_ind(t_asm *asmb, t_inst *ins, int oc)
{
	int			idx;
	int			i;

	i = oc == 0b10 ? 0 : -1;
	if (ins->ins[++i] == LABEL_CHAR)
		return (ft_get_label(asmb, ins, oc, i));
	idx = i;
	if (ins->ins[idx] == '-')
		idx++;
	while (ins->ins[idx])
		if (!ft_isdigit(ins->ins[idx++]))
			return (0);
	ins->param[ins->nb_instr] = ft_atoi_oflow(ins->ins + i);
	if (oc == 0b10)
	{
		if (!g_op_tab[ins->i_instr].label_size)
			ins->octet += 4;
		else
			ins->octet += 2;
	}
	else
		ins->octet += 2;
	return (get_ocp_return(ins, oc));
}
