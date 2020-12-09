/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:52:17 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 17:52:18 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		scene_keys(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(game->mlx.init, game->mlx.win);
		exit(0);
	}
	if (keycode == KEY_LEFTARROW)
		ft_rotate_left(game);
	if (keycode == KEY_RIGHTARROW)
		ft_rotate_right(game);
	if (keycode == KEY_UPARROW)
		ft_move_up(game);
	if (keycode == KEY_DOWNARROW)
		ft_move_down(game);
	if (keycode == KEY_ANSI_T)
		ft_enable_texture(game);
	if (keycode == KEY_ANSI_S)
		ft_less_speed(game);
	if (keycode == KEY_ANSI_X)
		ft_more_speed(game);
	if (keycode == KEY_ANSI_D)
		ft_look_up(game);
	if (keycode == KEY_ANSI_C)
		ft_look_down(game);
	ft_check_line(game);
	return (0);
}

void	ft_rotate_right(t_game *game)
{
	game->player.pov -= game->player.speed_rotation;
	game->player.pov = ft_correct_angle(game->player.pov);
}

void	ft_rotate_left(t_game *game)
{
	game->player.pov += game->player.speed_rotation;
	game->player.pov = ft_correct_angle(game->player.pov);
}
