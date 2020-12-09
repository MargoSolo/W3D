/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:40:20 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 15:40:23 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

t_col_dist	ft_check_vert_cp(t_game *game, double angle)
{
	t_coord		b;
	t_coord		delta;
	double		angle_r;
	t_col_dist	tmp;

	tmp.direct = 0;
	tmp.dist = 10000000;
	angle_r = ft_convert_angle_to_radian(angle);
	if ((angle == 270) || (angle == 90))
		return (tmp);
	if ((angle > 270) || (angle < 90))
		tmp.direct = 3;
	if ((angle > 90) && (angle < 270))
		tmp.direct = 4;
	b = ft_find_cp_y(game, game->player.position, angle);
	delta = ft_find_delta_y(game, angle);
	tmp.dist = ft_nearest_wall(game, b, delta, angle);
	return (tmp);
}

double		ft_convert_angle_to_radian(double angle)
{
	return (angle * M_PI / 180);
}

double		b2p(t_coord p1, t_coord p2)
{
	return ((double)sqrt((p1.x - p2.x) * (p1.x - p2.x)\
	+ (double)(p1.y - p2.y) * (p1.y - p2.y)));
}

void		innnnit(t_game *game)
{
	game->mlx.init = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.init, WIN_WIDTH, \
	WIN_HEIGHT, "W3D");
	ft_init_game(game);
}
