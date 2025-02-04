/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteichma <mteichma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:41:33 by mteichma          #+#    #+#             */
/*   Updated: 2025/02/02 13:30:51 by mteichma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *filename)
{
	char	*verif;

	verif = ft_strrchr(filename, '.');
	if (!verif)
	{
		ft_printf("Error\nFile must have an extension\n");
		return (0);
	}
	if (ft_strncmp(verif + 1, "ber", 3) != 0)
	{
		ft_printf("Error\nExtension must be .ber\n");
		return (0);
	}
	if (*(verif + 4) != '\0')
	{
		ft_printf("Error\nExtension must be exactly .ber\n");
		return (0);
	}
	return (1);
}

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCannot open the file\n");
		return (-1);
	}
	return (fd);
}
