/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:51:41 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 14:53:06 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_draw_minimap(t_game *game)
{
	int		size;
	t_coord	k;
	t_color	color;

	k.y = 0;
	size = WIN_WIDTH / 10 / game->map->width;
	color.r = 10;
	color.g = 10;
	color.b = 100;
	while (k.y < game->map->height)
	{
		k.x = 0;
		while (k.x < game->map->width)
		{
			if (game->map->val[(int)k.y][(int)k.x] != 0)
				ft_draw_cell(game, k, color, size);
			k.x++;
		}
		k.y++;
	}
	color.r = 100;
	color.b = 10;
	k.x = (int)(game->player.position.x / game->colwidth);
	k.y = (int)(game->player.position.y / game->colwidth);
	ft_draw_cell(game, k, color, size);
}

void	ft_draw_cell(t_game *game, t_coord k, t_color color, int size)
{
	int		x;
	int		y;

	y = size + size * k.y;
	while (y < (size + size * (k.y + 1)))
	{
		x = size + size * k.x;
		while (x < (size + size * (k.x + 1)))
		{
			ft_put_pixel(game, x, y, color);
			x++;
		}
		y++;
	}
}
