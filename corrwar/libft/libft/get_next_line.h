/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 03:51:53 by niludwig          #+#    #+#             */
/*   Updated: 2017/02/09 06:38:40 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_file
{
	int			fd;
	char		buff[BUFF_SIZE + 1];
	char		*chaine;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
