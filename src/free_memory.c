/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:49:49 by xlongfel          #+#    #+#             */
/*   Updated: 2020/12/08 17:49:50 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		free_1(t_player player)
{
	free(player.array_col_dist);
	free(player.array_col_dist);
}

void		free_memory(t_game *game)
{
	int		count;
	int		**z_matrix;

	count = 0;
	z_matrix = game->map->val;
	while (count < game->map->height)
	{
		free(z_matrix[count]);
		count++;
	}
	free(z_matrix);
	free_1(game->player);
	free(game);
}
