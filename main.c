/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:26:33 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/22 22:36:10 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg)
{
	ft_printf("Error\n%s", msg);
	exit(EXIT_FAILURE);
}

static int	check_file_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char	**map;
	t_game	game;

	if (ac != 2)
		exit_error("Usage: ./so_long <map.ber>\n");
	if (!check_file_extension(av[1]))
		exit_error("Map file must have .ber extension\n");
	map = load_map(av[1]);
	if (!map_is_valid(map))
		exit_error("Invalid map\n");
	init_game(&game, map);
	run_game(&game);
	return (0);
}
