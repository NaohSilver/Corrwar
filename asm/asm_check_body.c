/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_body.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:11:32 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:25:25 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_get_instr_len(char *f_content)
{
	int i;

	i = 0;
	while (!ft_iswhitespace(f_content[i]) && f_content[i] != DIRECT_CHAR
			&& f_content[i])
		i++;
	return (i);
}

int		ft_check_instr(t_list *labels, char *f_content, int i)
{
	int idx;
	int j;
	int label_size;

	idx = 0;
	j = 0;
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
	if (idx == 16)
		return (0);
	if (!(i = ft_parse_params(labels, f_content, i, idx)))
		return (0);
	return (i);
}

int		ft_is_label(char *f_content, int i)
{
	int x;

	x = i;
	while (ft_iswhitespace(f_content[x]))
		x++;
	while (ft_strchr(LABEL_CHARS, f_content[x]))
		x++;
	if (f_content[x] == LABEL_CHAR)
		return (ft_is_label(f_content, x + 1));
	return (i);
}

int		ft_check_body(t_list *labels, char *f_content, int i)
{
	if (!(f_content + i + 1))
		return (0);
	while (f_content[i])
	{
		if (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
		{
			i = ft_jump_nextline(f_content, i);
			continue;
		}
		if (!ft_iswhitespace(f_content[i]))
		{
			i = ft_is_label(f_content, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			while (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
				i = ft_jump_nextline(f_content, i);
			while (ft_iswhitespace(f_content[i]))
				i++;
			if (!(i = ft_check_instr(labels, f_content, i)))
				return (0);
		}
		else
			i++;
	}
	return (1);
}
