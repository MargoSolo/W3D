/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:45:14 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 15:45:15 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int				chk(t_game *game, double x, double y, double angle)
{
	int			tmp_x;
	int			tmp_y;

	tmp_y = (int)y / game->colwidth;
	tmp_x = (int)x / game->colwidth;
	if (x < 0)
		tmp_x = 0;
	if (y < 0)
		tmp_y = 0;
	if (y > game->map->height * game->colwidth)
		tmp_y = game->map->height - 1;
	if (x == game->map->width * game->colwidth)
		tmp_x = game->map->width - 1;
	if (game->map->val[tmp_y][tmp_x] == 0 || angle == -1000000)
		return (0);
	else
		return (1);
}

t_col_dist		ft_cast_ray(t_game *game, int i)
{
	t_col_dist	dist_horisontal;
	t_col_dist	dist_vertical;
	double		angle;

	angle = game->ray_angle * i + game->player.pov;
	angle = ft_correct_angle(angle);
	dist_horisontal = ft_check_horisont_cp(game, angle);
	dist_vertical = ft_check_vert_cp(game, angle);
	if (dist_horisontal.dist <= dist_vertical.dist)
		return (dist_horisontal);
	else
		return (dist_vertical);
}

double			ft_correct_angle(double angle)
{
	if (angle > 360)
		angle = angle - 360;
	if (angle < 0)
		angle = 360 + angle;
	return (angle);
}

t_coord			ft_find_cp_x(t_game *game, t_coord start_point, double angle)
{
	t_coord		a;
	double		angle_r;

	angle_r = ft_convert_angle_to_radian(angle);
	if (angle > 0 && angle < 180)
		a.y = (floor(start_point.y / game->colwidth) \
		* game->colwidth - 0.000001);
	else
		a.y = (floor(start_point.y / game->colwidth) \
		* game->colwidth + game->colwidth);
	a.x = start_point.x + (double)(start_point.y - a.y) / tan(angle_r);
	return (a);
}
