/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:55:41 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 14:55:46 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		ft_error(char *s)
{
	ft_putendl(s);
	return (0);
}

int		close_endian(void *param)
{
	(void)param;
	exit(0);
}

void	ft_init_game(t_game *game)
{
	game->colwidth = 300;
	game->colheight = 300;
	ft_start_player_point(game);
	game->player.fov = 60;
	game->player.pov = 45;
	game->player.speed = 30;
	game->player.speed_rotation = 10;
	game->player.array_col_dist = \
	(t_col_dist *)malloc(sizeof(t_col_dist) * WIN_WIDTH);
	game->player.max_dist = 0;
	game->player.min_dist = 0;
	game->ppdist = (WIN_WIDTH / 2) / tan(0.0174533 * game->player.fov / 2);
	game->ray_angle = (double)game->player.fov / WIN_WIDTH;
	game->player.centr_y = WIN_HEIGHT / 2;
	game->wall_color.r = 10;
	game->wall_color.g = 100;
	game->wall_color.b = 10;
	game->texture.on = 0;
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->mlx.win, 12, 0, expose_hook, game);
	mlx_hook(game->mlx.win, 2, 0, scene_keys, game);
	mlx_hook(game->mlx.win, 17, 0, close_endian, game);
}

int		expose_hook(t_game *game)
{
	mlx_put_image_to_window(game->mlx.init, game->mlx.win, game->mlx.img, 0, 0);
	return (1);
}
