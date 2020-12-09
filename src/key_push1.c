/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:17:23 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 12:17:44 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_look_up(t_game *game)
{
	if (game->player.centr_y + 50 < 6 * WIN_HEIGHT / 7)
		game->player.centr_y = game->player.centr_y + 50;
}

void	ft_look_down(t_game *game)
{
	if (game->player.centr_y - 50 > WIN_HEIGHT / 4)
		game->player.centr_y = game->player.centr_y - 50;
}

void	ft_less_speed(t_game *game)
{
	if (game->player.speed - 10 > game->colwidth / 10)
		game->player.speed = game->player.speed - 10;
}

void	ft_more_speed(t_game *game)
{
	if (game->player.speed + 10 < game->colwidth)
		game->player.speed = game->player.speed + 10;
}

void	ft_enable_texture(t_game *game)
{
	if (game->texture.on)
		game->texture.on = 0;
	else
		game->texture.on = 1;
}
