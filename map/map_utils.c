/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals <avinals-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:59:07 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/25 00:58:04 by avinals          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_elements(char **map, t_counts *count)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (!ft_strchr("01CEPX", map[i][j]))
				exit_error("Invalid character in map\n");
			if (map[i][j] == 'P')
				count->player++;
			if (map[i][j] == 'E')
				count->exit++;
			if (map[i][j] == 'C')
				count->collect++;
			j++;
		}
		i++;
	}
}

void	check_walls(char **map)
{
	int	height;
	int	width;
	int	i;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			exit_error("Map must be surrounded by walls\n");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			exit_error("Map must be surrounded by walls\n");
		i++;
	}
}

char	**copy_map(char **map)
{
	int		height;
	char	**copy;
	int		i;

	height = 0;
	while (map[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		exit_error("Error allocating memory for map copy\n");
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			exit_error("Error allocating memory for map copy\n");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
