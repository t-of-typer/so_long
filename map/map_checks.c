/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:52:58 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/22 22:35:04 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill_rec(char **map, t_flood_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		data->found_c++;
	if (map[y][x] == 'E')
		data->found_e++;
	map[y][x] = 'F';
	flood_fill_rec(map, data, x - 1, y);
	flood_fill_rec(map, data, x + 1, y);
	flood_fill_rec(map, data, x, y - 1);
	flood_fill_rec(map, data, x, y + 1);
}

static int	flood_fill_check(char **map, int total_collectibles)
{
	char			**map_copy;
	int				player_x;
	int				player_y;
	t_flood_data	data;

	map_copy = copy_map(map);
	data.found_c = 0;
	data.found_e = 0;
	data.height = 0;
	while (map[data.height])
		data.height++;
	data.width = ft_strlen(map[0]);
	if (map[0][data.width - 1] == '\n')
		data.width--;
	find_player(map_copy, &player_x, &player_y);
	flood_fill_rec(map_copy, &data, player_x, player_y);
	free_map_copy(map_copy);
	if (data.found_c != total_collectibles)
		exit_error("Not all collectibles are reachable\n");
	if (data.found_e == 0)
		exit_error("Exit is not reachable\n");
	return (1);
}

int	map_is_valid(char **map)
{
	t_counts	count;

	count.player = 0;
	count.exit = 0;
	count.collect = 0;
	count_map_elements(map, &count);
	if (count.player != 1)
		exit_error("It must be exactly one Player\n");
	if (count.exit != 1)
		exit_error("It must be exactly one Exit\n");
	if (count.collect < 1)
		exit_error("It must be at least one Collectible\n");
	check_walls(map);
	flood_fill_check(map, count.collect);
	return (1);
}
