/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:41:33 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 17:21:28 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot)
	{
		ft_printf("Error\nNo file extension found\n");
		return (0);
	}
	if (ft_strncmp(dot, ".ber", 4) != 0 || dot[4] != '\0')
	{
		ft_printf("Error\nExtension must be exactly .ber\n");
		return (0);
	}
	return (1);
}

int	check_args(t_game *game, int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nUsage: ./so_long map.ber\n");
		return (0);
	}
	if (!check_file_extension(av[1]))
		return (0);
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error\nCannot open file: %s\n", av[1]);
		return (0);
	}
	if (!read_and_parse_map(game))
	{
		close(game->fd);
		return (0);
	}
	close(game->fd);
	return (1);
}
