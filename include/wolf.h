/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:00:16 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 18:00:20 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define WIN_WIDTH		1000
# define WIN_HEIGHT		800
# define THREAD			8
# define T				0.0174533

# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "keys.h"
# include "../fmod/fmod.h"

typedef struct			s_map
{
	int					width;
	int					height;
	int					**val;
}						t_map;

typedef struct			s_img
{
	unsigned char		*data;
	int					size;
	int					endian;
	int					bpp;
}						t_img;

typedef struct			s_mlx
{
	void				*init;
	void				*win;
	void				*img;
}						t_mlx;

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;
typedef struct			s_coord
{
	double				x;
	double				y;
}						t_coord;

typedef struct			s_col_dist
{
	double				dist;
	int					direct;
}						t_col_dist;

typedef struct			s_player
{
	t_coord				position;
	double				fov;
	double				pov;
	int					speed;
	int					speed_rotation;
	t_col_dist			*array_col_dist;
	int					centr_y;
	double				max_dist;
	double				min_dist;
}						t_player;

typedef struct			s_texture
{
	void				*image;
	char				*name;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	int					width;
	int					height;
	int					*tab;
	int					on;
}						t_texture;

typedef struct			s_sound
{
	int					on;
	int					possible;
	char				*currentsound;
	FMOD_RESULT			result;
	FMOD_SYSTEM			*fmodsystem;
	FMOD_SOUND			*sound;
	FMOD_CHANNEL		*channel;
	FMOD_CHANNELGROUP	*music;
}						t_sound;

typedef struct			s_game
{
	t_map				*map;
	t_mlx				mlx;
	t_img				image;
	t_texture			texture;
	t_texture			texture_floor;
	t_texture			texture_sky;
	int					colwidth;
	int					colheight;
	t_player			player;
	t_color				wall_color;
	double				ppdist;
	double				ray_angle;
}						t_game;

t_map					*ft_read_map(char *path, int i, int h, int fd);
int						ft_error(char *s);
t_col_dist				ft_check_horisont_cp(t_game *game, double angle);
t_col_dist				ft_check_vert_cp(t_game *game, double angle);
void					ft_hooks(t_game *game);
int						expose_hook(t_game *game);
int						scene_keys(int keycode, t_game *game);
void					ft_rotate_left(t_game *game);
void					ft_rotate_right(t_game *game);
void					ft_check_line(t_game *g);
void					ft_move_up(t_game *game);
void					ft_move_down(t_game *game);
int						chk(t_game *game, double x, double y, double angle);
void					ft_draw_minimap(t_game *game);
void					ft_draw_cell(t_game *game, \
t_coord k, t_color color, int size);
void					ft_put_pixel(t_game *game, int i, int j, t_color color);
t_col_dist				ft_cast_ray(t_game *game, int i);
t_color					ft_get_texture_color(t_game *game,\
int row, int column, double shade);
void					ft_draw_sky(t_game *g, int start_wall, int i);
void					ft_draw_floor(t_game *game, int end_wall, int i);
int						load_texture_wall(t_game *game);
void					ft_enable_texture(t_game *game);
void					ft_more_speed(t_game *game);
void					ft_less_speed(t_game *game);
double					ft_correct_angle(double angle);
double					b2p(t_coord p1, t_coord p2);
double					ft_nearest_wall(t_game *game, \
t_coord a, t_coord delta, double angle);
t_coord					ft_find_cp_x(t_game *game, \
t_coord start_point, double angle);
t_coord					ft_find_cp_y(t_game *game, \
t_coord start_point, double angle);
t_coord					ft_find_delta_x(t_game *game, double angle);
t_coord					ft_find_delta_y(t_game *game, double angle);
t_col_dist				ft_check_horisont_cp(t_game *game, double angle);
t_col_dist				ft_check_vert_cp(t_game *game, double angle);
void					ft_look_down(t_game *game);
void					ft_look_up(t_game *game);
t_color					ft_shading(t_color color, double h);
int						check_map(t_map map);
int						check_border(t_map map);
int						close_endian(void *param);
t_sound					*initsound(void);
void					loadsound(t_sound *sound, const char *filename);
void					playsound(t_sound *sound, int pause);
int						load_texture_floor(t_game *game);
int						load_texture_sky(t_game *game);
t_color					ft_get_texture_color1(t_game *g, int row, int column);
t_color					ft_get_texture_color2(t_game *game,\
int row, int column);
void					ft_support(t_game *g, int a, t_coord cp, t_coord cv);
void					ft_support1(t_game *g, int a, t_coord cp, t_coord cv);
void					ft_init_game(t_game *game);
void					ft_start_player_point(t_game *game);
t_color					ft_get_wall_color(int i, double shade);
void					ft_put_column(t_game *g, int i, double h);
void					free_memory(t_game *game);
t_coord					ft_find_cp_x(t_game *game, \
t_coord start_point, double angle);
double					ft_convert_angle_to_radian(double angle);
double					ft_correct_angle(double angle);
t_col_dist				ft_cast_ray(t_game *game, int i);
int						chk(t_game *game, double x, double y, double angle);
int						check_res(char *filename);
void					iii(t_map *map, char *buff);
void					sound();
void					innnnit(t_game *game);

#endif
