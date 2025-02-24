/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:28 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 21:53:26 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_enemy
{
	int				x;
	int				y;
	int				dir_x;
	int				dir_y;
}					t_enemy;

typedef struct s_game
{
	int				fd;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	int				count_p;
	int				count_e;
	int				count_c;
	int				move_count;
	int				frame_count;
	int				scale_x;
	int				scale_y;
	int				tile_size;
	int				win_flag;
	int				win_start_frame;
	int				global_frame;
	int				text_x;
	int				text_y;
	int				text_color;
	char			**map;
	void			*mlx;
	void			*win;
	void			*wall_img;
	void			*floor_img;
	void			*item_img_1;
	void			*item_img_2;
	void			*player_img_1;
	void			*player_img_2;
	void			*player_idle_1;
	void			*player_idle_2;
	void			*player_move_1;
	void			*player_move_2;
	void			*player_win;
	void			*exit_img;
	void			*exit_closed_img;
	void			*exit_open_img;
	void			*player_dead;
	void			*enemy_move_1;
	void			*enemy_move_2;
	t_enemy			*enemies;
	int				enemy_count;
	void			*move_bg_img;
}					t_game;

int					check_args(t_game *game, int ac, char **av);
int					check_file_extension(char *filename);
int					check_line_length(char *line, int expected_width);
int					read_and_parse_map(t_game *game);
int					allocate_map(t_game *game);
int					check_rectangular(char **lines, int height, int width);
int					validate_map_content(t_game *game);
int					is_path_valid(t_game *game);
int					parse_lines(char **lines, t_game *game);
int					close_game_wrapper(t_game *game);
int					handle_keypress(int keycode, t_game *game);
int					update_game(t_game *game);
void				move_enemies(t_game *game);
void				init_window(t_game *game);
void				close_game(t_game *game);
void				free_map(char **map);
void				move_player(t_game *game, int new_x, int new_y);
void				render_map(t_game *game);
void				render_move_count(t_game *game);
void				render_move_count_bg(t_game *game);
int					close_window(t_game *game);
void				render_enemies(t_game *game);
void				render_player(t_game *game);
void				create_move_count_bg_image(t_game *game);
void				display_message(t_game *game, char *message);
void				free_images(t_game *game);
void				free_window_and_display(t_game *game);
void				free_map_and_exit(t_game *game);
void				init_game_struct(t_game *game);
void				load_images(t_game *game);
void				setup_window(t_game *game);

static inline int	free_lines_return(char **lines, int ret)
{
	int	i;

	if (!lines)
		return (ret);
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (ret);
}

static inline int	free_line_return(char *line, int ret)
{
	if (line)
		free(line);
	return (ret);
}

#endif
