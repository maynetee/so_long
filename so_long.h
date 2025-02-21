/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:28 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/14 23:58:54 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	int		fd;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		count_p;
	int		count_e;
	int		count_c;
	char	**map;
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*item_img;
	void	*exit_img;
	void	*player_img;
}	t_game;

int		check_args(t_game *game, int ac, char **av);
int		check_file_extension(char *filename);
int		main(int ac, char **av);
int		check_line_length(char *line, int expected_width);
int		read_and_parse_map(t_game *game);
void	free_map(char **map);
int		allocate_map(t_game *game);
int		check_rectangular(char **lines, int height, int width);
int		validate_map_content(t_game *game);
int		is_path_valid(t_game *game);
int		parse_lines(char **lines, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
void	render_map(t_game *game);
void	close_game(t_game *game);
int		close_game_wrapper(t_game *game);
void	init_window(t_game *game);
int		close_window(t_game *game);
int		handle_keypress(int keycode, t_game *game);

#endif
