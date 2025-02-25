/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:26:14 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 16:40:00 by mteichma         ###   ########.fr       */
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

	if (game->height < 1 || game->width < 1)
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
			game->map = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_rectangular(char **lines, int height, int width)
{
	int	i;
	int	len;

	i = 0;
	while (i < height)
	{
		len = ft_strlen(lines[i]);
		if (lines[i][len - 1] == '\n')
		{
			len--;
			lines[i][len] = '\0';
		}
		if (len != width)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	free_lines_return(char **lines, int ret)
{
	int	i;

	if (!lines)
		return (ret);
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (ret);
}

int	free_line_return(char *line, int ret)
{
	if (line)
		free(line);
	return (ret);
}
