/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:13:15 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:35:28 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_get_param(t_asm *asmb, t_inst *ins)
{
	int		flag;
	int		p_type;

	flag = 0;
	p_type = g_op_tab[ins->i_instr].param[ins->nb_instr];
	if (p_type & T_REG)
		ins->ocp |= ft_get_reg(ins);
	if (p_type & T_DIR)
	{
		flag = ins->ocp;
		if (*(ins->ins) == DIRECT_CHAR)
			ins->ocp |= ft_get_ind(asmb, ins, 0b10);
		flag = flag != ins->ocp ? 1 : 0;
	}
	if (!flag && p_type & T_IND)
		ins->ocp |= ft_get_ind(asmb, ins, 0b11);
	return (asmb->idx + ft_strlen(ins->ins));
}

int		ft_print_params(t_asm *asmb, t_inst *ins, int i)
{
	char	*f_content;

	if (g_op_tab[ins->i_instr].ocp)
		ins->octet++;
	ins->nb_instr = -1;
	ins->ocp = 0;
	asmb->idx = i;
	f_content = asmb->f_content;
	while (++ins->nb_instr < g_op_tab[ins->i_instr].nb_param)
	{
		while (ft_iswhitespace(f_content[asmb->idx]))
			asmb->idx++;
		if (f_content[asmb->idx] == SEPARATOR_CHAR)
			asmb->idx++;
		while (ft_iswhitespace(f_content[asmb->idx]))
			asmb->idx++;
		if ((ins->ins = ft_strsub(f_content, asmb->idx,
				ft_get_param_end(f_content, asmb->idx) - asmb->idx)) == NULL)
			return (0);
		asmb->idx = ft_get_param(asmb, ins);
		free(ins->ins);
	}
	ft_print_param(asmb, ins);
	return (asmb->idx);
}

int		ft_get_instr(t_asm *asmb, int i, t_inst *ins)
{
	char	*f_content;
	int		idx;
	int		label_size;

	idx = 0;
	f_content = asmb->f_content;
	label_size = 0;
	if (!f_content[i])
		return (i);
	while (g_op_tab[idx].name)
	{
		label_size = ft_get_instr_len(f_content + i);
		if (!(ft_strncmp(f_content + i, g_op_tab[idx].name, label_size)))
		{
			i += ft_strlen(g_op_tab[idx].name);
			break ;
		}
		idx++;
	}
	ins->octet += ft_printf("%c%@", idx + 1, asmb->fd);
	ins->ins_octet = ins->octet;
	ins->i_instr = idx;
	if (!(i = ft_print_params(asmb, ins, i)))
		return (0);
	return (i);
}

int		ft_get_label_pos(t_asm *asmb, t_inst *ins, int i)
{
	t_list		*tmp;
	t_label		*content;
	int			x;

	tmp = asmb->labels;
	while (ft_iswhitespace(asmb->f_content[i]))
		i++;
	while (tmp)
	{
		content = tmp->content;
		x = ft_strlen(content->label);
		if (!ft_strncmp(content->label, asmb->f_content + i, x))
		{
			if (asmb->f_content[i + x - 1] != LABEL_CHAR)
				return (i);
			content->addr = ins->octet + 1;
			return (ft_get_label_pos(asmb, ins, x + i));
		}
		tmp = tmp->next;
	}
	return (i);
}

void	ft_print_body(t_asm *asmb, char *f_content, int i)
{
	t_inst	ins;

	ins.octet = 0;
	while (f_content[i])
	{
		if ((f_content[i] == COMMENT_CHAR || f_content[i] == ';')
			&& (i = ft_jump_nextline(f_content, i)))
			continue;
		if (!ft_iswhitespace(f_content[i]))
		{
			i = ft_get_label_pos(asmb, &ins, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			while (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
				i = ft_jump_nextline(f_content, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			if (!(i = ft_get_instr(asmb, i, &ins)))
				return ;
		}
		else
			i++;
	}
	asmb->prog_size = ins.octet;
}
