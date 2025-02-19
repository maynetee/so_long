/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:28:57 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/14 23:41:37 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C'
		|| c == 'E' || c == 'P');
}

int	check_and_store_line(char *line, t_game *game, int y)
{
	int	x;

	if (!game || !line)
		return (0);
	x = 0;
	while (line[x] && line[x] != '\n' && x < game->width)
	{
		if (!is_valid_char(line[x]))
			return (0);
		game->map[y][x] = line[x];
		if (line[x] == 'P')
		{
			if (game->count_p == 1)
				return (0);
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
	return (x == game->width);
}
