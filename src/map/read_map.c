/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:10:51 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/04 14:04:52 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*trim_newline(char *line)
{
	int i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
	return (line);
}

static int	count_file_lines(char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_map(char *path)
{
	char	**map;
	int		line_count;
	int		fd;
	int		i;

	line_count = count_file_lines(path);
	if (line_count <= 0)
		return (NULL);
	map = ft_calloc(sizeof(char *), line_count + 1);
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		map[i] = trim_newline(map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
