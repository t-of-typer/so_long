/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:00:00 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 17:09:04 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_ui_background(t_game *game)
{
	game->ui_background = create_colored_image_size(game, UI_COLOR,
			game->window_width, UI_HEIGHT);
	if (!game->ui_background)
		exit_error("Error creating UI background\n");
}

void	render_ui_text(t_game *game)
{
	char	*moves_str;
	char	*collectibles_str;
	char	*moves_text;
	char	*collect_text;

	moves_str = ft_itoa(game->moves);
	collectibles_str = ft_itoa(game->collectibles);
	moves_text = ft_strjoin("Moves: ", moves_str);
	collect_text = ft_strjoin("Flowers left: ", collectibles_str);
	mlx_string_put(game->mlx, game->window,
		10, 20, TEXT_COLOR, moves_text);
	mlx_string_put(game->mlx, game->window,
		200, 20, TEXT_COLOR, collect_text);
	free(moves_str);
	free(collectibles_str);
	free(moves_text);
	free(collect_text);
}

void	render_ui(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->ui_background, 0, 0);
	render_ui_text(game);
}

void	cleanup_ui(t_game *game)
{
	if (game->ui_background)
		mlx_destroy_image(game->mlx, game->ui_background);
}

void	*create_colored_image(t_game *game, int color)
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (!img)
		return (NULL);
	data = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	fill_image_with_color(data, color, bits_per_pixel, line_length);
	return (img);
}
