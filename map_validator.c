/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:54:30 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/14 23:58:03 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1'
			|| game->map[game->height - 1][i] != '1')
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1'
			|| game->map[i][game->width - 1] != '1')
		{
			ft_printf("Error\nMap must be surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map_content(t_game *game)
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
	if (!check_walls(game))
		return (0);
	if (!is_path_valid(game))
		return (0);
	return (1);
}
