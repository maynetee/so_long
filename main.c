/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:12 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 19:41:53 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
	game->move_count = 0;
	game->frame_count = 0;
	game->scale_x = 0;
	game->scale_y = 0;
	game->tile_size = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->wall_img = NULL;
	game->floor_img = NULL;
	game->item_img_1 = NULL;
	game->item_img_2 = NULL;
	game->player_idle_1 = NULL;
	game->player_idle_2 = NULL;
	game->player_move_1 = NULL;
	game->player_move_2 = NULL;
	game->player_win = NULL;
	game->exit_closed_img = NULL;
	game->exit_open_img = NULL;
	game->global_frame = 0;
	game->win_flag = 0;
	game->win_start_frame = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	init_game_struct(&game);
	if (!check_args(&game, ac, av))
		return (1);
	init_window(&game);
	return (0);
}
