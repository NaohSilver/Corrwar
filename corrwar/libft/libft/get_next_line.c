/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 01:09:58 by niludwig          #+#    #+#             */
/*   Updated: 2016/12/17 07:48:45 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*ft_get_all(int fd, t_list *lst)
{
	t_file			*new;

	if (lst->content && ((t_file*)lst->content)->fd == fd)
		return (lst);
	else if (lst->next)
		return (ft_get_all(fd, lst->next));
	else
	{
		if (!(new = (t_file*)malloc(sizeof(t_file))))
			return (0);
		new->fd = fd;
		new->chaine = new->buff + BUFF_SIZE;
		ft_bzero(new->buff, BUFF_SIZE + 1);
		if (!(lst->next = (t_list*)malloc(sizeof(t_list))))
			return (0);
		lst->next->next = 0;
		lst->next->content = new;
		return (lst->next);
	}
}

static int			ft_poney(char **line, t_file *chaine)
{
	char			*tmp;
	char			*tmpl;

	tmpl = *line;
	if ((tmp = ft_strchr(chaine->chaine, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strjoin(*line, chaine->chaine)))
			return (-1);
		free(tmpl);
		chaine->chaine = tmp + 1;
		return (1);
	}
	if (!(*line = ft_strjoin(*line, chaine->chaine)))
		return (-1);
	free(tmpl);
	chaine->chaine = chaine->buff + BUFF_SIZE;
	return (0);
}

static int			ft_join(char **line, t_file *chaine_buff)
{
	char			*tmp;

	tmp = *line;
	*chaine_buff->chaine++ = '\0';
	if (!(*line = ft_strjoin(tmp, chaine_buff->buff)))
		return (-1);
	free(tmp);
	return (1);
}

static int			ft_get_one(const int fd, char **line, t_file *content)
{
	int				tmp;
	int				boul;

	boul = 0;
	while ((tmp = read(fd, content->buff, BUFF_SIZE)) > 0)
	{
		boul = 1;
		content->buff[tmp] = '\0';
		if ((content->chaine = ft_strchr(content->buff, '\n')))
			return (ft_join(line, content));
		content->chaine = content->buff + tmp;
		if (ft_join(line, content) == -1)
			return (-1);
		content->chaine = content->buff + tmp;
	}
	return ((tmp == -1) ? -1 : boul);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	lst_fd;
	t_list			*lst;
	t_file			*content;
	int				tmp;
	int				boul;

	boul = 0;
	if (!(lst = ft_get_all(fd, &lst_fd)) || !line)
		return (-1);
	content = lst->content;
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (*(content->chaine))
	{
		if ((tmp = ft_poney(line, content)) || tmp == -1)
			return (tmp);
		boul = 1;
	}
	if ((tmp = ft_get_one(fd, line, content)) != 0)
		return (tmp);
	free(lst->content);
	lst->content = 0;
	return (boul);
}
