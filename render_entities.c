/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_entities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:49:46 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 15:49:50 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player_buffer(t_game *game)
{
	int		pos_x;
	int		pos_y;
	void	*player_img;

	pos_x = game->player.x * game->tile_size;
	pos_y = game->player.y * game->tile_size;
	if (game->win_status == 1)
		player_img = game->assets.player_win;
	else if (game->win_status == 2)
		player_img = game->assets.player_dead;
	else
	{
		if ((game->global_frame / 30) % 2 == 0)
			player_img = game->assets.player_idle_1;
		else
			player_img = game->assets.player_idle_2;
	}
	if (player_img)
		blit_img(game, player_img, pos_x, pos_y);
}

void	render_enemies_buffer(t_game *game)
{
	int		i;
	int		pos_x;
	int		pos_y;
	void	*enemy_img;

	i = 0;
	while (i < game->enemy_count)
	{
		pos_x = game->enemies[i].x * game->tile_size;
		pos_y = game->enemies[i].y * game->tile_size;
		if ((game->global_frame / 30) % 2 == 0)
			enemy_img = game->assets.enemy_move_1;
		else
			enemy_img = game->assets.enemy_move_2;
		if (enemy_img)
			blit_img(game, enemy_img, pos_x, pos_y);
		i++;
	}
}

void	prepare_buffer(t_game *game)
{
	int	x;
	int	y;
	int	win_height;

	win_height = game->tile_size * game->height;
	ft_bzero(game->buffer_addr, game->buffer_size_line * win_height);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile_buffer(game, x, y);
			x++;
		}
		y++;
	}
}
