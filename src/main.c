/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:59:35 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 15:59:36 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		ft_start_player_point(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->val[i][j] == 0)
			{
				game->player.position.x = j * \
				game->colwidth + (int)game->colwidth / 2;
				game->player.position.y = i * \
				game->colwidth + (int)game->colwidth / 2;
			}
			j++;
		}
		i++;
	}
}

void		ft_put_column(t_game *g, int i, double h)
{
	int			start_point;
	int			end_point;
	t_color		wall_color;
	int			j;
	double		shade;

	shade = (double)(g->player.array_col_dist[i].dist - g->player.min_dist)\
	/ (1.3 * (g->player.max_dist - g->player.min_dist));
	start_point = (int)((g->player.centr_y / 2) - (h / 2));
	start_point = start_point < 0 ? 1 : start_point;
	end_point = (int)((g->player.centr_y / 2) + h / 2);
	end_point = end_point >= WIN_HEIGHT ? WIN_HEIGHT - 1 : end_point;
	wall_color = ft_get_wall_color(g->player.array_col_dist[i].direct, shade);
	ft_draw_sky(g, start_point, i);
	ft_draw_floor(g, end_point, i);
	while (start_point < end_point)
	{
		if (g->texture.on == 1)
		{
			j = ((start_point - WIN_HEIGHT * 0.4f + h * 0.4f) * \
			10 * g->texture.height) / h;
			wall_color = ft_get_texture_color(g, j, i, shade);
		}
		ft_put_pixel(g, i, start_point++, wall_color);
	}
}

int			checker(t_game *game)
{
	if (!check_map(*game->map))
		return (ft_error("Map error"));
	if (!check_border(*game->map))
		return (ft_error("Border error"));
	if (game->map->height <= 3 || game->map->width <= 3)
		return (ft_error("Map is too small"));
	if (!load_texture_wall(game) ||\
	!load_texture_floor(game) || !load_texture_sky(game))
		return (ft_error("Problem with textures"));
	return (1);
}

void		sound(void)
{
	t_sound		*sound;

	sound = initsound();
	loadsound(sound, "1.mp3");
	playsound(sound, 0);
	free(sound);
}

int			main(int arc, char **argv)
{
	t_game		*game;
	int			fd;
	int			i;
	int			h;

	h = 0;
	i = 0;
	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (ft_error("allocation memory error"));
	if (arc == 2)
	{
		if ((fd = open(argv[1], O_RDWR) == -1))
			return (ft_error("file path error"));
		game->map = ft_read_map(argv[1], i, h, fd);
		innnnit(game);
		if (!checker(game))
			return (0);
		sound();
		ft_check_line(game);
		ft_hooks(game);
		mlx_loop(game->mlx.init);
	}
	else
		return (ft_error("parameter error"));
	free_memory(game);
}
