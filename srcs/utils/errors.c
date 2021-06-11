/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:54:30 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/11 07:28:52 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_error(char c, t_map *map)
{
	if (c == 'r' || c == 't')
		printf("Invalid file path\nRetry\n");
	else if (c == 'l')
		printf("Error in reading config line\nRetry\n");
	else if (c == 'g')
		printf("Invalid rgba configuration\nRetry\n");
	else if (c == 'd')
		printf("Invalid direction configuration\nRetry\n");
	else if (c == 'e')
		printf("Invalid file extension\nRetry\n");
	else if (c == 'x')
		printf("Invalid value declaration in config\nRetry\n");
	else if (c == 'm' || c == 'w')
		printf("Invalid map\nRetry\n");
	else if (c == 'p')
		printf("Invalid player position\nRetry\n");
	else if (c == 'y')
		printf("An error occurred in mlx library\nRetry\n");
	else if (c == 'o')
		printf("An error occurred when opening the file\nRetry\n");
	else if (c == 'i')
		printf("Map file empty\nRetry\n");
	(void)map;
	return (1);
}
