/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:52:36 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/06 20:35:47 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_line_length(char *line, t_game *game)
{
	size_t	len;

	if (!line || !game)
		return (0);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	return (len == (size_t)game->width);
}

static int	process_line(char *line, t_game *game, int i)
{
	if (!line || !game || i < 0 || i >= game->height)
	{
		free(line);
		return (0);
	}
	if (!validate_line_length(line, game) || !check_and_store_line(line, game,
			i))
	{
		free(line);
		if (game->map)
			free_map(game->map);
		return (0);
	}
	free(line);
	return (1);
}

static int	init_map_reading(char *filename, t_game *game, int *fd)
{
	if (!game || !filename)
		return (0);
	*fd = open_map_file(filename);
	if (*fd == -1)
		return (0);
	if (!allocate_map(game))
	{
		close(*fd);
		return (0);
	}
	return (1);
}

static int	process_map_lines(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && i < game->height)
	{
		if (!process_line(line, game, i++))
		{
			close(fd);
			return (0);
		}
		line = get_next_line(fd);
	}
	return (i);
}

int	read_map_file(char *filename, t_game *game)
{
	int	fd;
	int	lines_read;

	if (!init_map_reading(filename, game, &fd))
		return (0);
	lines_read = process_map_lines(fd, game);
	close(fd);
	return (lines_read == game->height && validate_map_content(game));
}
