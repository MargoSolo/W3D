/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:02 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 17:50:07 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	ft_support(t_game *g, int a, t_coord cp, t_coord cv)
{
	double	dist;
	int		ind;

	ind = 0;
	if (b2p(g->player.position, cv) >= b2p(g->player.position, cp))
	{
		dist = b2p(g->player.position, cp);
		if ((dist > g->player.speed) || (chk(g, cp.x, cp.y, a) == 0))
			ind = 1;
	}
	else
	{
		dist = b2p(g->player.position, cv);
		if ((dist > g->player.speed) || (chk(g, cv.x, cv.y, a) == 0))
			ind = 1;
	}
	if ((ind == 1) && (chk(g, g->player.position.x + cos(a * T) * \
	g->player.speed, g->player.position.y - sin(a * T) * \
	g->player.speed, a) == 0))
	{
		g->player.position.x = g->player.position.x + \
		cos(a * T) * g->player.speed;
		g->player.position.y = g->player.position.y - \
		sin(a * T) * g->player.speed;
	}
}

void	ft_move_up(t_game *game)
{
	t_coord	cp_horis;
	t_coord	cp_vert;
	int		angle;

	angle = game->player.pov + game->player.fov / 2;
	angle = ft_correct_angle(angle);
	cp_horis = ft_find_cp_x(game, game->player.position, angle);
	cp_vert = ft_find_cp_y(game, game->player.position, angle);
	ft_support(game, angle, cp_horis, cp_vert);
}

void	ft_support1(t_game *g, int a, t_coord cp, t_coord cv)
{
	double	dist;
	int		ind;

	ind = 0;
	if (b2p(g->player.position, cv) >= b2p(g->player.position, cp))
	{
		dist = b2p(g->player.position, cp);
		if ((dist > g->player.speed) || (chk(g, cp.x, cp.y, a) == 0))
			ind = 1;
	}
	else
	{
		dist = b2p(g->player.position, cv);
		if ((dist > g->player.speed) || (chk(g, cv.x, cv.y, a) == 0))
			ind = 1;
	}
	if ((ind == 1) && (chk(g, g->player.position.x - cos(a * T) * \
	g->player.speed, g->player.position.y + sin(a * T) * g->player.speed,\
	a) == 0))
	{
		g->player.position.x = g->player.position.x - \
		cos(a * T) * g->player.speed;
		g->player.position.y = g->player.position.y + \
		sin(a * T) * g->player.speed;
	}
}

void	ft_move_down(t_game *game)
{
	t_coord	cp_horis;
	t_coord	cp_vert;
	int		angle;
	int		ind;

	ind = 0;
	angle = game->player.pov + game->player.fov / 2;
	angle = ft_correct_angle(angle);
	cp_horis = ft_find_cp_x(game, game->player.position, angle);
	cp_vert = ft_find_cp_y(game, game->player.position, angle);
	ft_support1(game, angle, cp_horis, cp_vert);
}
