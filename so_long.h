/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:28 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/21 02:00:59 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
	void	*floor_img;
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
void	free_images(t_game *game);
void	free_window_and_display(t_game *game);
void	free_map_and_exit(t_game *game);
void	close_game(t_game *game);
int		close_game_wrapper(t_game *game);

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
