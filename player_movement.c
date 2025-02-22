/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:53:09 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 19:35:48 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move_to(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'E' && game->count_c > 0)
		return (0);
	return (1);
}

void	collect_item(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->count_c--;
		game->map[new_y][new_x] = '0';
		system("afplay assets/item.wav &");
	}
}

void	check_victory(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E' && game->count_c == 0)
	{
		system("afplay assets/victory.wav &");
		display_message(game, "You Win!");
		ft_printf("You Win!\n");
		game->win_flag = 1;
		game->win_start_frame = game->global_frame;
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (can_move_to(game, new_x, new_y))
	{
		game->move_count++;
		ft_printf("Mouvements : %d\n", game->move_count);
		collect_item(game, new_x, new_y);
		check_victory(game, new_x, new_y);
		game->player_x = new_x;
		game->player_y = new_y;
		mlx_clear_window(game->mlx, game->win);
		mlx_do_sync(game->mlx);
		render_map(game);
	}
}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * game->tile_size, y
		* game->tile_size);
}

void	render_player(t_game *game, int x, int y)
{
	if (game->count_c == 0 && game->map[y][x] == 'E')
	{
		put_image(game, game->player_win, x, y);
		return ;
	}
	if (game->player_x != x || game->player_y != y)
	{
		if (game->frame_count < 10)
			put_image(game, game->player_move_1, x, y);
		else
			put_image(game, game->player_move_2, x, y);
	}
	else
	{
		if (game->frame_count < 10)
			put_image(game, game->player_idle_1, x, y);
		else
			put_image(game, game->player_idle_2, x, y);
	}
	game->frame_count++;
	if (game->frame_count > 20)
		game->frame_count = 0;
}

void	render_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] != '1')
		put_image(game, game->floor_img, x, y);
	if (game->map[y][x] == '1')
		put_image(game, game->wall_img, x, y);
	if (game->map[y][x] == 'C')
	{
		if (game->frame_count < 10)
			put_image(game, game->item_img_1, x, y);
		else
			put_image(game, game->item_img_2, x, y);
	}
	if (game->map[y][x] == 'E')
	{
		if (game->count_c == 0)
			put_image(game, game->exit_open_img, x, y);
		else
			put_image(game, game->exit_closed_img, x, y);
	}
	if (game->player_x == x && game->player_y == y)
		render_player(game, x, y);
}

void	render_move_count(t_game *game)
{
	char	*move_str;
	int		x;
	int		y;
	int		color_text;
	int		color_bg;
	int		bg_width;
	int		bg_height;

	move_str = ft_itoa(game->move_count);

	color_text = 0x8B0000;
	color_bg = 0xF5DEB3;

	bg_width = 200;
	bg_height = 40;

	x = (game->width * game->tile_size) / 2 - bg_width / 2;
	y = 10;

	int	x_start = x;
	int	y_start = y;
	int	x_end = x_start + bg_width;
	int	y_end = y_start + bg_height;

	int	i = x_start;
	int	j = y_start;

	while (j < y_end)
	{
		i = x_start;
		while (i < x_end)
		{
			mlx_pixel_put(game->mlx, game->win, i, j, color_bg);
			i++;
		}
		j++;
	}

	mlx_string_put(game->mlx, game->win, x + 30, y + 15, color_text, "Moves: ");
	mlx_string_put(game->mlx, game->win, x + 130, y + 15, color_text, move_str);

	free(move_str);
}


void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_move_count(game);
	game->frame_count++;
	if (game->frame_count > 20)
		game->frame_count = 0;
}
