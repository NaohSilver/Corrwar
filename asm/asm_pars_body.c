/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_body.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:12:49 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:35:15 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_list	*ft_init_label(char *label)
{
	t_list		*new;
	t_label		*tmp;

	if (label == NULL)
		return (NULL);
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((tmp = (t_label*)malloc(sizeof(t_label))) == NULL)
		return (NULL);
	tmp->label = label;
	tmp->addr = -1;
	new->content = tmp;
	new->next = NULL;
	return (new);
}

int		ft_save_label(t_asm *asmb, int i, int j)
{
	t_list	*new;
	char	*label;

	if (asmb->f_content[i] == LABEL_CHAR)
	{
		if ((label = ft_strsub(asmb->f_content, j, i + 1 - j)) == NULL)
			return (0);
		if ((new = ft_init_label(label)) == NULL)
			return (0);
		ft_lstaddtail(&asmb->labels, new);
	}
	return (1);
}

int		ft_get_labels(t_asm *asmb)
{
	char	*f_content;
	int		i;
	int		j;

	f_content = asmb->f_content;
	i = asmb->idx;
	while (f_content[i])
	{
		if (f_content[i] == COMMENT_CHAR || f_content[i] == ';')
			i = ft_jump_nextline(f_content, i);
		if (ft_strchr(LABEL_CHARS, f_content[i]))
		{
			j = i;
			while (ft_strchr(LABEL_CHARS, f_content[i]))
				i++;
			if (!ft_save_label(asmb, i, j))
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_get_param_end(char *f_content, int i)
{
	while (f_content[i] != SEPARATOR_CHAR && !ft_iswhitespace(f_content[i])
		&& f_content[i] && f_content[i] != COMMENT_CHAR && f_content[i] != ';')
		i++;
	return (i);
}

int		asm_parse_body(t_asm *asmb)
{
	if (!ft_get_labels(asmb))
		return (0);
	if (!ft_check_body(asmb->labels, asmb->f_content, asmb->idx))
		return (0);
	return (1);
}
