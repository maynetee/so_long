/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:28 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/06 19:32:26 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/includes/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	int		count_p;
	int		count_e;
	int		count_c;
}			t_game;

/*                            file_checks.c                            */
int			check_file_extension(char *filename);
int			open_map_file(char *filename);

/*                            map_checks.c                            */
int			check_map_dimensions(int fd, t_game *game);

/*                            map_utils.c                             */
void		free_map(char **map);
int			allocate_map(t_game *game);

/*                            map_parser.c                             */
int			read_map_file(char *filename, t_game *game);
int			validate_map_content(t_game *game);

#endif
