/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:52:36 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/14 23:59:52 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		*lines = ft_realloc_tab(*lines, i + 1);
		if (!*lines)
			return (free_line_return(line, 0));
		(*lines)[i++] = line;
		line = get_next_line(game->fd);
	}
	game->height = i;
	if (game->height < 1)
		return (free_lines_return(*lines, 0));
	return (1);
}

static int	check_and_store_line(char *line, t_game *game, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n' && x < game->width)
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != 'C'
			&& line[x] != 'E' && line[x] != 'P')
		{
			ft_printf("Error\nInvalid char in map: %c\n", line[x]);
			return (0);
		}
		game->map[y][x] = line[x];
		if (line[x] == 'P' && ++game->count_p > 1)
			return (0);
		else if (line[x] == 'E' && ++game->count_e > 1)
			return (0);
		else if (line[x] == 'C')
			game->count_c++;
		x++;
	}
	return (1);
}

static int	parse_lines(char **lines, t_game *game)
{
	int	y;

	if (!allocate_map(game))
		return (0);
	y = 0;
	while (y < game->height)
	{
		if (!check_and_store_line(lines[y], game, y))
			return (0);
		y++;
	}
	return (1);
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
