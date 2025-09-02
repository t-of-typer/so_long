/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:00:00 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 16:57:40 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	exit_game(game);
	return (0);
}

static int	check_move_validity(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->width || new_y < 0
		|| new_y >= game->height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E' && game->collectibles > 0)
		return (0);
	return (1);
}

static void	handle_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collectibles--;
	}
	if (game->map[new_y][new_x] == 'X')
	{
		ft_printf("You lost! Touched an enemy.\n");
		ft_printf("Total moves: %d\n", game->moves + 1);
		exit_game(game);
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		ft_printf("You won! Moves: %d\n", game->moves + 1);
		exit_game(game);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (dx > 0)
		game->player_direction = DIRECTION_RIGHT;
	else if (dx < 0)
		game->player_direction = DIRECTION_LEFT;
	if (check_move_validity(game, new_x, new_y))
		handle_move(game, new_x, new_y);
}

int	handle_keypress(int key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0, -1);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, 0, 1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1, 0);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 0);
	render_map(game);
	return (0);
}
