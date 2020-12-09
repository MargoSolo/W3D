/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:46:08 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 17:46:10 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		load_texture_wall(t_game *game)
{
	game->texture.name = "xpm/earth.xpm";
	game->texture.image = mlx_xpm_file_to_image(game->mlx.init,\
	game->texture.name, &game->texture.width, &game->texture.height);
	game->texture.data = mlx_get_data_addr(game->texture.image,\
	&game->texture.bpp, &game->texture.size_line, &game->texture.endian);
	return (1);
}

int		load_texture_sky(t_game *game)
{
	game->texture_sky.name = "xpm/sky.xpm";
	game->texture_sky.image = mlx_xpm_file_to_image(game->mlx.init,\
	game->texture_sky.name, &game->texture_sky.width, \
	&game->texture_sky.height);
	game->texture_sky.data = mlx_get_data_addr(game->texture_sky.image,\
	&game->texture_sky.bpp, &game->texture_sky.size_line, \
	&game->texture_sky.endian);
	return (1);
}

int		load_texture_floor(t_game *game)
{
	game->texture_floor.name = "xpm/floor.xpm";
	game->texture_floor.image = mlx_xpm_file_to_image(game->mlx.init,\
	game->texture_floor.name, &game->texture_floor.width, \
	&game->texture_floor.height);
	game->texture_floor.data = mlx_get_data_addr(game->texture_floor.image,\
	&game->texture_floor.bpp, &game->texture_floor.size_line, \
	&game->texture_floor.endian);
	return (1);
}

t_color	ft_get_texture_color(t_game *game, int row, int column, double shade)
{
	int		i;
	t_color color;

	if (row < 0)
		row = -row;
	if (column < 0)
		column = -column;
	if (column >= game->texture.height)
		column = column % game->texture.height;
	if (row >= game->texture.width)
		row = row % game->texture.width;
	i = row * game->texture.size_line + game->texture.bpp / 8 * column;
	color.b = (int)(unsigned char)game->texture.data[i];
	color.g = (int)(unsigned char)game->texture.data[i + 1];
	color.r = (int)(unsigned char)game->texture.data[i + 2];
	color = ft_shading(color, shade);
	return (color);
}
