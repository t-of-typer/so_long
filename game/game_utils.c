/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:00:00 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 17:06:27 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	cleanup_images(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	cleanup_images(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_player_right)
		mlx_destroy_image(game->mlx, game->img_player_right);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx, game->img_player_left);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	cleanup_animation_frames(game);
	cleanup_ui(game);
}

void	exit_game(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	fill_image_with_color(char *data, int color, int bpp, int line_len)
{
	int	i;
	int	j;
	int	pixel_index;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			pixel_index = (i * line_len) + (j * (bpp / 8));
			*(unsigned int *)(data + pixel_index) = color;
			j++;
		}
		i++;
	}
}

void	fill_img_rect(char *data, int color, int specs[4])
{
	int	i;
	int	j;
	int	pixel_index;

	i = 0;
	while (i < specs[3])
	{
		j = 0;
		while (j < specs[2])
		{
			pixel_index = (i * specs[1]) + (j * (specs[0] / 8));
			*(unsigned int *)(data + pixel_index) = color;
			j++;
		}
		i++;
	}
}
