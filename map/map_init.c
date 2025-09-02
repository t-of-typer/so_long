/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:40:08 by avinals-          #+#    #+#             */
/*   Updated: 2025/07/22 22:34:24 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_and_get_width(char *line, int expected)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	if (expected == -1)
		return (len);
	if (len != expected)
		exit_error("Map is not rectangular\n");
	return (expected);
}

char	**list_to_map(t_list *lines)
{
	int		height;
	int		width;
	char	**map;
	int		i;
	t_list	*tmp;

	height = ft_lstsize(lines);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		exit_error("Malloc error while converting map\n");
	width = -1;
	i = 0;
	while (lines)
	{
		map[i] = lines->content;
		width = validate_and_get_width(map[i], width);
		tmp = lines;
		lines = lines->next;
		free(tmp);
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_list	*read_map_lines(const char *filepath)
{
	int		fd;
	t_list	*lines;
	t_list	*new;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open map file\n");
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
			exit_error("Malloc error while reading map\n");
		ft_lstadd_back(&lines, new);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

char	**load_map(const char *filepath)
{
	t_list	*lines;
	char	**map;

	lines = read_map_lines(filepath);
	map = list_to_map(lines);
	return (map);
}
