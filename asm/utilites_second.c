/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:52:48 by niludwig          #+#    #+#             */
/*   Updated: 2017/06/12 18:58:40 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strjoin_n_free(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (str);
}

char	*ft_get_file_content(char *file_name)
{
	char	*file_content;
	char	*buffer;
	int		fd;

	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &buffer) > 0)
	{
		file_content = ft_strjoin_n_free(file_content, buffer);
		file_content = ft_strjoin_n_free(file_content, "\n");
		free(buffer);
	}
	close(fd);
	return (file_content);
}

int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	else
		return (0);
}

int		ft_return(char *int_min, char *int_max, int ret)
{
	free(int_min);
	free(int_max);
	return (ret);
}

int		ft_strisint(char *nbr)
{
	int		i;
	char	*int_min;
	char	*int_max;

	i = -1;
	int_min = ft_itoa(INT_MIN);
	int_max = ft_itoa(INT_MAX);
	if ((nbr[0] != '-' && ft_strlen(nbr) < ft_strlen(int_max)) ||
		(nbr[0] == '-' && ft_strlen(nbr) < ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 1));
	else if ((nbr[0] != '-' && ft_strlen(nbr) > ft_strlen(int_max)) ||
			(nbr[0] == '-' && ft_strlen(nbr) > ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 0));
	if (nbr[0] == '-' && ++i + 1)
		while (nbr[++i] != '\0')
			if (nbr[i] > int_min[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[0] != '-')
		while (nbr[++i] != '\0')
			if (nbr[i] > int_max[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[i] == '\0')
		return (ft_return(int_min, int_max, 1));
	return (ft_return(int_min, int_max, 0));
}
