/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:26:14 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/02 13:26:16 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	allocate_map(t_game *game)
{
	int	i;

	if (game->height < 3 || game->width < 3)
		return (0);
	game->map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		return (0);
	i = 0;
	while (i < game->height)
	{
		game->map[i] = (char *)ft_calloc(game->width + 1, sizeof(char));
		if (!game->map[i])
		{
			free_map(game->map);
			return (0);
		}
		i++;
	}
	game->map[i] = NULL;
	return (1);
}
