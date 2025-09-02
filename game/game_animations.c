/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:00:00 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 16:53:21 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_animation_system(t_game *game)
{
	game->animation_frame = 0;
	game->animation_counter = 0;
}

void	update_enemy_animation(t_game *game)
{
	game->animation_counter++;
	if (game->animation_counter >= 2400)
	{
		game->animation_frame = (game->animation_frame + 1) % 3;
		game->animation_counter = 0;
		render_map(game);
	}
}

int	has_enemies_on_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'X')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	animation_loop(t_game *game)
{
	if (has_enemies_on_map(game))
		update_enemy_animation(game);
	return (0);
}

void	cleanup_animation_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->img_enemy_frames[i])
			mlx_destroy_image(game->mlx, game->img_enemy_frames[i]);
		i++;
	}
}
