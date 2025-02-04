/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:28:57 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/02 14:39:31 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		/* Ici nous devrons :
			1. Copier la ligne dans game->map[i]
			2. Libérer la ligne
			3. Incrémenter i
			4. Lire la ligne suivante */
	}
}
