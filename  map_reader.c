/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    map_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:52:36 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/06 19:52:38 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	process_line(char *line, t_game *game, int i)
{
	if (!check_and_store_line(line, game, i))
	{
		free(line);
		free_map(game->map);
		return (0);
	}
	free(line);
	return (1);
}

int	read_map_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	if (!game || !filename || (fd = open_map_file(filename)) == -1)
		return (0);
	if (!allocate_map(game))
	{
		close(fd);
		return (0);
	}
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
	close(fd);
	return (i == game->height && validate_map_content(game));
}
