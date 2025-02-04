/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:40:50 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/02 13:31:01 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	process_first_line(char *line, t_game *game)
{
	if (!line)
		return (0);
	if (line[ft_strlen(line) - 1] == '\n')
		game->width = ft_strlen(line) - 1;
	else
		game->width = ft_strlen(line);
	if (game->width < 3)
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

static int	check_line_length(char *line, size_t width)
{
	size_t	line_len;

	if (!line)
		return (0);
	if (line[ft_strlen(line) - 1] == '\n')
		line_len = ft_strlen(line) - 1;
	else
		line_len = ft_strlen(line);
	return (line_len == width);
}

int	check_map_dimensions(int fd, t_game *game)
{
	char	*line;
	int		line_count;

	line = get_next_line(fd);
	if (!process_first_line(line, game))
		return (0);
	line_count = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (!check_line_length(line, game->width))
		{
			free(line);
			return (0);
		}
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line_count < 3)
		return (0);
	game->height = line_count;
	close(fd);
	return (1);
}
