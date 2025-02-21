/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:12 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/14 23:57:18 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_struct(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
	game->fd = -1;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_game_struct(&game);
	if (!check_args(&game, ac, av))
		return (1);
	init_window(&game);
	close_game(&game);
	return (0);
}
