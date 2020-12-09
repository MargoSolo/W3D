/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:45:29 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 16:19:55 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_coord		ft_find_delta_x(t_game *game, double angle)
{
	t_coord		delta;
	double		angle_r;

	angle_r = ft_convert_angle_to_radian(angle);
	if (angle > 0 && angle < 180)
		delta.y = -game->colwidth;
	else
		delta.y = game->colwidth;
	delta.x = (double)-game->colwidth / tan(angle_r);
	if (angle > 0 && angle < 180)
		delta.x *= -1;
	return (delta);
}

t_col_dist	ft_check_horisont_cp(t_game *game, double angle)
{
	t_coord		a;
	t_coord		delta;
	int			ind;
	t_col_dist	tmp;
	double		angle_r;

	tmp.direct = 0;
	tmp.dist = 10000000;
	ind = 0;
	angle_r = ft_convert_angle_to_radian(angle);
	if ((angle >= 0) && (angle <= 180))
		tmp.direct = 1;
	else
		tmp.direct = 2;
	a = ft_find_cp_x(game, game->player.position, angle);
	delta = ft_find_delta_x(game, angle);
	tmp.dist = ft_nearest_wall(game, a, delta, angle);
	return (tmp);
}

double		ft_nearest_wall(t_game *game, t_coord a,\
		t_coord delta, double angle)
{
	while (1 == 1)
	{
		if (((int)(a.x / game->colwidth) >= game->map->width) ||\
				((int)(a.y / game->colwidth) >= game->map->height))
			return (10000000);
		if (((int)(a.x / game->colwidth) < 0) \
				|| ((int)(a.y / game->colwidth) < 0))
			return (10000000);
		if (chk(game, a.x, a.y, angle) == 1)
			return (b2p(game->player.position, a));
		a.x = a.x + delta.x;
		a.y = a.y + delta.y;
	}
}

t_coord		ft_find_cp_y(t_game *game, t_coord start_point, double angle)
{
	t_coord		a;
	double		angle_r;

	angle_r = ft_convert_angle_to_radian(angle);
	if (angle > 90 && angle < 270)
		a.x = (floor(start_point.x / game->colwidth) \
				* game->colwidth - 0.00000001);
	else
		a.x = (floor(start_point.x / game->colwidth) * \
				game->colwidth + game->colwidth);
	a.y = start_point.y + (start_point.x - a.x) * tan(angle_r);
	return (a);
}

t_coord		ft_find_delta_y(t_game *game, double angle)
{
	t_coord		delta;
	double		angle_r;

	angle_r = ft_convert_angle_to_radian(angle);
	if (angle > 270 || angle < 90)
		delta.x = game->colwidth;
	if (angle < 270 && angle > 90)
		delta.x = -game->colwidth;
	delta.y = -game->colwidth * tan(angle_r);
	if (angle < 270 && angle > 90)
		delta.y *= -1;
	return (delta);
}
