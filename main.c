/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:12 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/01 16:48:03 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 500, 500, "Ma premiere fenetre");
	if (!game->win)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
	{
		ft_printf("Error\n Should be used this way: ./so_long map.ber\n");
		return (1);
	}
	if (!check_file_extension(av[1]))
		return (1);
	fd = open_map_file(av[1]);
	if (fd == -1)
		return (1);
	if (!check_map_dimensions(fd, &game))
	{
		ft_printf("Error\nInvalid map dimensions\n");
		return (1);
	}
	if (!init_mlx_window(&game))
		return (1);
	mlx_loop(game.mlx);
	return (0);
}
