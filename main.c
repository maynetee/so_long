/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:12 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 15:40:44 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_assets(t_game *game)
{
	game->assets.wall = NULL;
	game->assets.floor = NULL;
	game->assets.exit_open = NULL;
	game->assets.exit_closed = NULL;
	game->assets.item_1 = NULL;
	game->assets.item_2 = NULL;
	game->assets.player_idle_1 = NULL;
	game->assets.player_idle_2 = NULL;
	game->assets.player_move_1 = NULL;
	game->assets.player_move_2 = NULL;
	game->assets.player_win = NULL;
	game->assets.player_dead = NULL;
	game->assets.enemy_move_1 = NULL;
	game->assets.enemy_move_2 = NULL;
	game->assets.move_bg = NULL;
}

static void	init_player(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 0;
}

static void	init_game_values(t_game *game)
{
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
	game->frame_count = 0;
	game->global_frame = 0;
	game->win_status = 0;
	game->win_start_frame = 0;
	game->tile_size = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->enemies = NULL;
	game->enemy_count = 0;
	init_assets(game);
	init_player(game);
}

void	init_game_struct(t_game *game)
{
	init_game_values(game);
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
