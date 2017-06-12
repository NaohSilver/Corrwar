/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:13:02 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 15:35:21 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_skip_spaces(char *line)
{
	int i;

	i = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	return (i);
}

/*
** 10 -> parsed name;
** 01 -> parsed comment;
*/

int		ft_get_param_value(char *f_content, char *curr_param, int i,
								unsigned int max_size)
{
	unsigned int tmp;

	i += ft_skip_spaces(f_content + i);
	if (f_content[i] == '\"')
	{
		i++;
		tmp = ft_strccpy(curr_param, f_content + i, '\"');
		if (tmp > max_size)
			return (0);
		i += tmp;
	}
	if (!f_content[i])
		return (0);
	return (i + 1);
}

int		ft_handle_hlabel(t_asm *asmb, char *f_content
									, int i, char *parse_state)
{
	char			*curr_param;
	unsigned int	max_size;

	if (!ft_strncmp(f_content + i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		*parse_state |= 2;
		curr_param = asmb->prog_name;
		max_size = PROG_NAME_LENGTH;
		i += ft_strlen(NAME_CMD_STRING);
	}
	else
	{
		*parse_state |= 1;
		curr_param = asmb->comment;
		max_size = COMMENT_LENGTH;
		i += ft_strlen(COMMENT_CMD_STRING);
	}
	return (ft_get_param_value(f_content, curr_param, i, max_size));
}

int		ft_check_name_n_comm(t_asm *asmb, int i, int state)
{
	if (!ft_strncmp(asmb->f_content + i, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)))
	{
		if (!CHECK_BIT(state, 1))
			return (1);
		else
			return (0);
	}
	else if (!ft_strncmp(asmb->f_content + i, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)))
	{
		if (!CHECK_BIT(state, 0))
			return (1);
		else
			return (0);
	}
	return (0);
}

int		asm_parse_header(t_asm *asmb)
{
	char	*f_content;
	int		i;
	int		tmp;
	char	parse_state;

	i = 0;
	tmp = 0;
	parse_state = 0;
	f_content = asmb->f_content;
	while (parse_state != 3)
	{
		i += ft_skip_spaces(f_content + i);
		tmp = i;
		if ((f_content[i] == COMMENT_CHAR) || (f_content[i] == ';'))
			while (f_content[tmp] && f_content[tmp] != '\n')
				tmp++;
		else if (!ft_check_name_n_comm(asmb, i, parse_state))
			return (0);
		else if (!(tmp = ft_handle_hlabel(asmb, f_content, i, &parse_state)))
			return (0);
		i = tmp;
	}
	asmb->idx = i;
	return (1);
}
