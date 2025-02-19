/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:40:50 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/14 23:57:30 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line_length(char *line, int expected_width)
{
	int	len;

	len = 0;
	if (!line)
		return (0);
	while (line[len] && line[len] != '\n')
		len++;
	return (len == expected_width);
}
