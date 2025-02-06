/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:12 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/06 20:10:59 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_mlx_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 500, 500, "So Long");
	if (!game->win)
	{
		free(game->mlx);
		return (0);
	}
	return (1);
}

static void	init_game_struct(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = -1;
	game->player_y = -1;
	game->collectibles = 0;
	game->moves = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
}

int	main(int ac, char **av)
{
	t_game	game;
	int		fd;

	if (ac != 2)
	{
		ft_printf("Error\nUse this program this way: ./so_long map.ber\n");
		return (1);
	}
	init_game_struct(&game);
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
