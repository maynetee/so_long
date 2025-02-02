/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:28 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/01 18:26:50 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "Libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
}   t_game;

/* map_checks.c */
int     check_map_dimensions(int fd, t_game *game);

/* file_checks.c */
int     check_file_extension(char *filename);
int     open_map_file(char *filename);

#endif