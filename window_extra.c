/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:52 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 21:52:33 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    display_message(t_game *game, char *message)
{
    int x;
    int y;
    int color;

    x = 10;
    y = 50;
    color = 0xFFFFFF;
    if (!game->win_flag)
        mlx_string_put(game->mlx, game->win, x, y, color, message);
}

/*
 * Définition unique de render_move_count_bg
 * Evite le multiple definition.
 */
void    render_move_count_bg(t_game *game, int x, int y)
{
    (void)game;
    (void)x;
    (void)y;
    /*
     * Implémentez si vous voulez un rectangle d'arrière-plan
     * pour le compteur. Sinon laissez vide.
     */
}
