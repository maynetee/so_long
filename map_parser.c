/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:28:57 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 15:41:02 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'X');
}

static void	store_enemy(t_game *game, int x, int y)
{
	t_enemy	*new_enemies;
	int		i;

	new_enemies = ft_calloc(game->enemy_count + 1, sizeof(t_enemy));
	if (!new_enemies)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		new_enemies[i] = game->enemies[i];
		i++;
	}
	new_enemies[i].x = x;
	new_enemies[i].y = y;
	new_enemies[i].dir_x = 1;
	new_enemies[i].dir_y = 0;
	free(game->enemies);
	game->enemies = new_enemies;
	game->enemy_count++;
}

static void	update_game_counts(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		if (game->count_p == 1)
			game->count_p = -1;
		else
		{
			game->count_p++;
			game->player.x = x;
			game->player.y = y;
		}
	}
	else if (c == 'E')
		game->count_e++;
	else if (c == 'C')
		game->count_c++;
	else if (c == 'X')
		store_enemy(game, x, y);
}

static int	check_and_store_line(char *line, t_game *game, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n' && x < game->width)
	{
		if (!is_valid_map_char(line[x]))
		{
			ft_printf("Error\nInvalid char in map: %c\n", line[x]);
			return (0);
		}
		game->map[y][x] = line[x];
		update_game_counts(game, line[x], x, y);
		if (line[x] == 'X')
			game->map[y][x] = '0';
		if (game->count_p == -1)
		{
			ft_printf("Error\nMap must contain exactly one player (P)\n");
			return (0);
		}
		x++;
	}
	return (1);
}

int	parse_lines(char **lines, t_game *game)
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
