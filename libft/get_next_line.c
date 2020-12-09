/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblueber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:04:28 by pblueber          #+#    #+#             */
/*   Updated: 2019/11/13 14:15:10 by pblueber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		get_line(char **line, char **hv, int fd)
{
	int		i;
	char	*t;

	i = 0;
	while (hv[fd][i] != '\n')
		i++;
	*line = ft_strsub(hv[fd], 0, i);
	t = ft_strdup(hv[fd] + i + 1);
	free(hv[fd]);
	hv[fd] = t;
	return (1);
}

int		get_last_line(char **line, char **hv, int fd)
{
	if (ft_strlen(hv[fd]) > 1)
	{
		*line = ft_strdup(hv[fd]);
		hv[fd][0] = '\0';
		return (1);
	}
	else
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			str[BUFF_SIZE + 1];
	static char		*hv[4096];
	char			*t;

	if ((fd < 0) || (line == NULL))
		return (-1);
	if (hv[fd] == NULL)
		hv[fd] = ft_strnew(0);
	if ((ft_strchr(hv[fd], '\n')))
		return (get_line(line, hv, fd));
	while (((ret = read(fd, str, BUFF_SIZE)) > 0))
	{
		str[ret] = '\0';
		t = ft_strjoin(hv[fd], str);
		free(hv[fd]);
		hv[fd] = t;
		if (ft_strchr(hv[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if ((ret == 0) && (!(ft_strchr(hv[fd], '\n'))))
		return (get_last_line(line, hv, fd));
	return (get_next_line(fd, line));
}
