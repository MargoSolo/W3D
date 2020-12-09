/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:04:01 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 15:34:28 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static t_color	r(int i, t_color color)
{
	if (i == 1)
	{
		color.r = 0;
		color.g = 54;
		color.b = 255;
	}
	if (i == 2)
	{
		color.r = 255;
		color.g = 23;
		color.b = 99;
	}
	if (i == 3)
	{
		color.r = 0;
		color.g = 255;
		color.b = 56;
	}
	if (i == 4)
	{
		color.r = 255;
		color.g = 132;
		color.b = 15;
	}
	return (color);
}

t_color			ft_get_wall_color(int i, double shade)
{
	t_color		color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	color = r(i, color);
	return (ft_shading(color, shade));
}

void			ft_put_wall_to_data(t_game *game)
{
	int			i;
	double		h;

	i = 0;
	while (i < WIN_WIDTH)
	{
		if (game->player.array_col_dist[i].dist > 0)
		{
			h = game->colheight / game->player.array_col_dist[i].dist \
			* game->ppdist;
			ft_put_column(game, i, h);
		}
		i++;
	}
}

void			ft_check_line(t_game *g)
{
	int			i;

	i = 0;
	g->mlx.img = mlx_new_image(g->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	g->image.data = (unsigned char*)mlx_get_data_addr(g->mlx.img, \
	&g->image.bpp, &g->image.size, &g->image.endian);
	while (i < WIN_WIDTH)
	{
		g->player.array_col_dist[WIN_WIDTH - i] = ft_cast_ray(g, i);
		if ((g->player.min_dist == 0) || (g->player.array_col_dist[WIN_WIDTH - \
		i].dist < g->player.min_dist))
			g->player.min_dist = g->player.array_col_dist[WIN_WIDTH - i].dist;
		if ((g->player.array_col_dist[WIN_WIDTH - i].dist > g->player.max_dist)\
		&& (g->player.array_col_dist[WIN_WIDTH - i].dist != 10000000))
			g->player.max_dist = g->player.array_col_dist[WIN_WIDTH - i].dist;
		i++;
	}
	ft_put_wall_to_data(g);
	ft_draw_minimap(g);
	mlx_put_image_to_window(g->mlx.init, g->mlx.win, g->mlx.img, 0, 0);
	mlx_destroy_image(g->mlx.init, g->mlx.img);
}

void			ft_put_pixel(t_game *game, int i, int j, t_color color)
{
	int			p;

	p = 4 * (WIN_WIDTH * j + i);
	game->image.data[p + 2] = color.r;
	game->image.data[p + 1] = color.g;
	game->image.data[p] = color.b;
}
