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

int	get_error(char c)
{
	if (c == 'r' || c == 't')
		printf("Error\nInvalid file path\nRetry\n");
	else if (c == 'l')
		printf("Error\nError in reading config line\nRetry\n");
	else if (c == 'g')
		printf("Error\nInvalid rgba configuration\nRetry\n");
	else if (c == 'd')
		printf("Error\nInvalid direction configuration\nRetry\n");
	else if (c == 'e')
		printf("Error\nInvalid file extension\nRetry\n");
	else if (c == 'x')
		printf("Error\nInvalid value declaration in config\nRetry\n");
	else if (c == 'm' || c == 'w')
		printf("Error\nInvalid map\nRetry\n");
	else if (c == 'p')
		printf("Error\nInvalid player position\nRetry\n");
	else if (c == 'y')
		printf("Error\nAn error occurred in mlx library\nRetry\n");
	else if (c == 'o')
		printf("Error\nAn error occurred when opening the file\nRetry\n");
	else if (c == 'i')
		printf("Error\nMap file empty\nRetry\n");
	return (1);
}
