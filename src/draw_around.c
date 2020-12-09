/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:45 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 17:50:46 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_color		ft_get_texture_color2(t_game *game, int row, int column)
{
	int		i;
	t_color	color;

	if (row < 0)
		row = -row;
	if (column < 0)
		column = -column;
	if (column >= game->texture_sky.height)
		column = column % game->texture_sky.height;
	if (row >= game->texture_sky.width)
		row = row % game->texture_sky.width;
	i = row * game->texture_sky.size_line + game->texture_sky.bpp / 8 * column;
	color.b = (int)(unsigned char)game->texture_sky.data[i];
	color.g = (int)(unsigned char)game->texture_sky.data[i + 1];
	color.r = (int)(unsigned char)game->texture_sky.data[i + 2];
	return (color);
}

t_color		ft_get_texture_color1(t_game *g, int row, int column)
{
	int		i;
	t_color	color;

	if (row < 0)
		row = -row;
	if (column < 0)
		column = -column;
	if (column >= g->texture_floor.height)
		column = column % g->texture_floor.height;
	if (row >= g->texture_floor.width)
		row = row % g->texture_floor.width;
	i = row * g->texture_floor.size_line + g->texture_floor.bpp / 8 * column;
	color.b = (int)(unsigned char)g->texture_floor.data[i];
	color.g = (int)(unsigned char)g->texture_floor.data[i + 1];
	color.r = (int)(unsigned char)g->texture_floor.data[i + 2];
	return (color);
}

void		ft_draw_sky(t_game *g, int start_wall, int i)
{
	int		s_point;
	int		end_point;
	t_color	sky_color;
	double	k;

	if (start_wall > 1)
	{
		end_point = start_wall - 1;
		s_point = 1;
		while (s_point < end_point)
		{
			k = (double)(s_point) / (g->player.centr_y - g->player.min_dist);
			if (g->texture.on == 1)
				sky_color = ft_get_texture_color2(g, s_point, i);
			else
			{
				sky_color.r = 255;
				sky_color.g = 0;
				sky_color.b = 0;
			}
			sky_color = ft_shading(sky_color, k);
			ft_put_pixel(g, i, s_point, sky_color);
			s_point++;
		}
	}
}

void		ft_draw_floor(t_game *game, int end_wall, int i)
{
	int		start_point;
	int		end_point;
	t_color	floor_color;
	double	k;

	if (end_wall < WIN_HEIGHT)
	{
		end_point = WIN_HEIGHT;
		start_point = end_wall + 1;
		while (start_point < end_point)
		{
			k = 1 - (double)start_point / WIN_HEIGHT;
			if (game->texture.on == 1)
				floor_color = ft_get_texture_color1(game, start_point, i);
			else
			{
				floor_color.r = 0;
				floor_color.g = 20;
				floor_color.b = 155;
			}
			floor_color = ft_shading(floor_color, k);
			ft_put_pixel(game, i, start_point, floor_color);
			start_point++;
		}
	}
}
