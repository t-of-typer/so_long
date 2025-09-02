/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:47:41 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/24 19:51:13 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	expose_hook(t_game *game)
{
	render_map(game);
	return (0);
}

void	run_game(t_game *game)
{
	mlx_loop(game->mlx);
}
