/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:11:27 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 16:39:15 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_image(void **img, void *mlx, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	return (*img != NULL);
}

int	load_all_images(t_game *game)
{
	return (load_image(&game->assets.wall, game->mlx, "assets/wall.xpm")
		&& load_image(&game->assets.floor, game->mlx, "assets/floor.xpm")
		&& load_image(&game->assets.exit_closed, game->mlx,
			"assets/exit_closed.xpm")
		&& load_image(&game->assets.exit_open, game->mlx,
			"assets/exit_open.xpm")
		&& load_image(&game->assets.item_1, game->mlx, "assets/item_1.xpm")
		&& load_image(&game->assets.item_2, game->mlx, "assets/item_2.xpm")
		&& load_image(&game->assets.player_idle_1, game->mlx,
			"assets/player_idle_1.xpm")
		&& load_image(&game->assets.player_idle_2, game->mlx,
			"assets/player_idle_2.xpm")
		&& load_image(&game->assets.player_move_1, game->mlx,
			"assets/player_move_1.xpm")
		&& load_image(&game->assets.player_move_2, game->mlx,
			"assets/player_move_2.xpm")
		&& load_image(&game->assets.player_win, game->mlx,
			"assets/player_win.xpm")
		&& load_image(&game->assets.player_dead, game->mlx,
			"assets/player_dead.xpm")
		&& load_image(&game->assets.enemy_move_1, game->mlx,
			"assets/enemy_move_1.xpm")
		&& load_image(&game->assets.enemy_move_2, game->mlx,
			"assets/enemy_move_2.xpm"));
}

void	init_window(t_game *game)
{
	if (!setup_window(game))
	{
		free_window_and_display(game);
		free_map_and_exit(game);
		return ;
	}
	if (!load_all_images(game))
	{
		ft_printf("Error\nFailed to load images\n");
		close_game(game);
		return ;
	}
	create_move_count_bg_image(game);
	render_map(game);
	mlx_hook(game->win, 17, 0, close_game_wrapper, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_loop(game->mlx);
}
