/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:52:36 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/20 04:21:59 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	process_line(char ***lines, char **line, int *i)
{
	if ((*line)[0] == '\n')
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	*lines = ft_realloc_tab(*lines, *i + 1);
	if (!*lines)
		return (free_line_return(*line, 0));
	(*lines)[(*i)++] = *line;
	*line = NULL;
	return (1);
}

static int	store_lines(t_game *game, char ***lines)
{
	char	*line;
	int		i;

	*lines = ft_calloc(1, sizeof(char *));
	if (!*lines)
		return (0);
	i = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		if (!process_line(lines, &line, &i))
			return (0);
		if (!line)
			line = get_next_line(game->fd);
	}
	game->height = i;
	return (game->height > 0);
}

int	read_and_parse_map(t_game *game)
{
	char	**lines;

	lines = NULL;
	if (!store_lines(game, &lines))
		return (0);
	game->width = (int)ft_strlen(lines[0]);
	if (lines[0][game->width - 1] == '\n')
		game->width--;
	if (!check_rectangular(lines, game->height, game->width))
		return (free_lines_return(lines, 0));
	if (!parse_lines(lines, game))
		return (free_lines_return(lines, 0));
	if (!validate_map_content(game))
		return (free_lines_return(lines, 0));
	free_lines_return(lines, 1);
	return (1);
}
