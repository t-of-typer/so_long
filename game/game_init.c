/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:00:00 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 16:58:40 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	game->collectibles = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
	game->total_collectibles = game->collectibles;
}

static void	set_game_dimensions(t_game *game, char **map)
{
	game->map = map;
	game->height = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	if (map[0][game->width - 1] == '\n')
		game->width--;
}

void	init_game(t_game *game, char **map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error("Error initializing MLX\n");
	set_game_dimensions(game, map);
	game->window_width = game->width * TILE_SIZE;
	game->window_height = (game->height * TILE_SIZE) + UI_HEIGHT;
	game->window = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "So Long");
	if (!game->window)
		exit_error("Error creating window\n");
	game->moves = 0;
	game->player_direction = DIRECTION_RIGHT;
	find_player_position(game);
	count_collectibles(game);
	load_images(game);
	create_ui_background(game);
	init_animation_system(game);
	mlx_key_hook(game->window, handle_keypress, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_expose_hook(game->window, expose_hook, game);
	mlx_loop_hook(game->mlx, animation_loop, game);
	render_map(game);
}
