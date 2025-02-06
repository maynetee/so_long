/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:28:57 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/06 19:32:12 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static int	check_and_store_line(char *line, t_game *game, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (!is_valid_char(line[x]))
			return (0);
		game->map[y][x] = line[x];
		if (line[x] == 'P')
		{
			game->count_p++;
			game->player_x = x;
			game->player_y = y;
		}
		else if (line[x] == 'E')
			game->count_e++;
		else if (line[x] == 'C')
			game->count_c++;
		x++;
	}
	return (1);
}

int validate_map_content(t_game *game)
{
    if (game->count_p != 1)
    {
        ft_printf("Error\nMap must contain exactly one player (P)\n");
        return (0);
    }
    if (game->count_e != 1)
    {
        ft_printf("Error\nMap must contain exactly one exit (E)\n");
        return (0);
    }
    if (game->count_c < 1)
    {
        ft_printf("Error\nMap must contain at least one collectible (C)\n");
        return (0);
    }
    return (1);
}

int	read_map_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open_map_file(filename);
	if (fd == -1)
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
		if (!check_and_store_line(line, game, i))
		{
			free(line);
			close(fd);
			free_map(game->map);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (validate_map_content(game));
}
