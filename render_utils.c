/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:00 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 21:51:56 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:16:00 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/22 21:51:56 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_message(t_game *game, char *message)
{
	mlx_string_put(game->mlx, game->win, 10, 60, 0xFFFFFF, message);
}

void	render_move_count(t_game *game)
{
	char	*count_str;
	int		color;

	if (game->assets.move_bg)
		blit_img(game, game->assets.move_bg, 0, 0);
	count_str = ft_itoa(game->player.moves);
	if (!count_str)
		return ;
	color = 0xFFFFFF;
	mlx_string_put(game->mlx, game->win, 10, 20, color, "Moves:");
	mlx_string_put(game->mlx, game->win, 60, 20, color, count_str);
	free(count_str);
}
