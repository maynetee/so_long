/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:48:09 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/06 20:30:39 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(char **map_copy, int height)
{
	int	i;

	if (!map_copy)
		return ;
	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	if (!game || !game->map)
		return (NULL);
	copy = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			free_map_copy(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

static int	check_reachable(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if ((game->map[y][x] == 'C' || game->map[y][x] == 'E')
				&& map[y][x] != 'F')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_path_valid(t_game *game)
{
	char	**map_copy;
	int		result;

	if (!game)
		return (0);
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_x, game->player_y, game);
	result = check_reachable(map_copy, game);
	if (!result)
		ft_printf("Error\nNo valid path to all collectibles and exit\n");
	free_map_copy(map_copy, game->height);
	return (result);
}
