/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:28 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/25 15:53:25 by mteichma         ###   ########.fr       */
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

typedef struct s_assets
{
	void			*wall;
	void			*floor;
	void			*exit_open;
	void			*exit_closed;
	void			*item_1;
	void			*item_2;
	void			*player_idle_1;
	void			*player_idle_2;
	void			*player_move_1;
	void			*player_move_2;
	void			*player_win;
	void			*player_dead;
	void			*enemy_move_1;
	void			*enemy_move_2;
	void			*move_bg;
}					t_assets;

typedef struct s_player
{
	int				x;
	int				y;
	int				moves;
}					t_player;

typedef struct s_game
{
	int				fd;
	int				width;
	int				height;
	int				count_p;
	int				count_e;
	int				count_c;
	int				frame_count;
	int				global_frame;
	int				win_status;
	int				win_start_frame;
	int				tile_size;
	char			**map;
	void			*mlx;
	void			*win;
	t_assets		assets;
	t_player		player;
	t_enemy			*enemies;
	int				enemy_count;
	void			*buffer;
	char			*buffer_addr;
	int				buffer_bpp;
	int				buffer_size_line;
	int				buffer_endian;
}					t_game;

typedef struct s_blit_data
{
	int				src_bpp;
	int				src_sl;
	char			*src;
	unsigned int	*dest;
	unsigned int	*src_pixel;
}					t_blit_data;

/* File: file_checks.c */
int					check_file_extension(char *filename);
int					check_args(t_game *game, int ac, char **av);

/* File: map_checks.c */
int					check_line_length(char *line, int expected_width);

/* File: map_utils.c */
void				free_map(char **map);
int					allocate_map(t_game *game);
int					check_rectangular(char **lines, int height, int width);
int					free_lines_return(char **lines, int ret);
int					free_line_return(char *line, int ret);

/* File: map_reader.c */
int					read_and_parse_map(t_game *game);

/* File: map_parser.c */
int					parse_lines(char **lines, t_game *game);

/* File: map_validator.c */
int					validate_map_content(t_game *game);

/* File: path_check.c */
int					is_path_valid(t_game *game);

/* File: events.c */
int					handle_keypress(int keycode, t_game *game);
int					close_game_wrapper(t_game *game);

/* File: game_cleanup.c */
void				close_game(t_game *game);
void				free_images(t_game *game);
void				free_window_and_display(t_game *game);
void				free_map_and_exit(t_game *game);

/* File: player_movement.c */
int					can_move_to(t_game *game, int x, int y);
void				move_player(t_game *game, int new_x, int new_y);

/* File: enemy.c */
void				move_enemies(t_game *game);
int					update_game(t_game *game);

/* File: render_map.c */
void				blit_img(t_game *game, void *src_img,
						int dest_x, int dest_y);
void				render_map(t_game *game);
void				render_tile_buffer(t_game *game, int x, int y);

/* File: render_entities.c */
void				render_player_buffer(t_game *game);
void				render_enemies_buffer(t_game *game);
void				prepare_buffer(t_game *game);

/* File: render_utils.c */
void				render_move_count(t_game *game);

/* File: window.c */
void				init_window(t_game *game);
int					load_all_images(t_game *game);
int					load_image(void **img, void *mlx, char *path);

/* File: window_extra.c */
void				create_move_count_bg_image(t_game *game);
void				calc_window_size(t_game *game, int *width, int *height);
void				initialize_mlx(t_game *game);

/* File: window_setup.c */
void				setup_window(t_game *game);
void				create_window(t_game *game, int width, int height);
void				create_buffer(t_game *game, int width, int height);

/* File: main.c */
void				init_game_struct(t_game *game);

#endif
