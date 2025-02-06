/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:57:31 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/06 19:57:54 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	process_line(char *line, t_game *game, int i)
{
	int	result;

	result = check_and_store_line(line, game, i);
	if (!result)
	{
		free(line);
		free_map(game->map);
		return (0);
	}
	free(line);
	return (1);
}
