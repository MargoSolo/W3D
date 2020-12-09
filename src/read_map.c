/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:59:30 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 16:59:33 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_map	*ft_read_map(char *path, int i, int h, int fd)
{
	t_map	*map;
	char	*buff;
	int		w;

	w = 0;
	map = malloc(sizeof(t_map));
	if ((fd = open(path, O_RDWR)) == -1)
		ft_error("file path error");
	buff = ft_strnew(1000);
	read(fd, buff, 1000);
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			h++;
		w++;
		i++;
	}
	map->height = h;
	map->width = w / (h + 1);
	map->val = (int **)malloc(sizeof(int *) * map->height);
	iii(map, buff);
	close(fd);
	free(buff);
	return (map);
}

void	iii(t_map *map, char *buff)
{
	int		i;
	char	c;
	int		w;
	int		j;

	i = 0;
	w = 0;
	j = 0;
	while (i < map->height)
	{
		map->val[i] = (int *)malloc(sizeof(int) * map->width);
		j = 0;
		while (j < map->width)
		{
			c = buff[i * (map->width + 1) + j];
			map->val[i][j] = ft_atoi(&c);
			j++;
		}
		i++;
	}
}

int		check_map(t_map map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.val[i][j] > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_border(t_map map)
{
	int		y;
	int		x;

	y = 0;
	x = -1;
	while (++x < map.width)
	{
		if (map.val[y][x] != 1)
			return (0);
	}
	while (++y < map.height - 1)
	{
		if (map.val[y][0] != 1 || map.val[y][map.width - 1] != 1)
			return (0);
	}
	x = -1;
	while (++x < map.width)
	{
		if (map.val[y][x] != 1)
			return (0);
	}
	return (1);
}
