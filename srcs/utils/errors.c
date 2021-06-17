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

int	free_line(char *l)
{
	if (l)
		free(l);
	l = NULL;
	return (0);
}

int	check_err(int err, int space, t_map *map)
{
	if (!err && !space && check_bottom_wall(map, map->maze[map->idx - 1]))
		return (get_error('w'));
	return (err);
}

void	free_parse(t_map *map)
{
	int	i;

	i = -1;
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->s)
		free(map->s);
	if (map->trim)
		free(map->trim);
	if (map->line)
		free(map->line);
	while (map->maze && map->maze[++i])
		free(map->maze[i]);
	if (map->maze)
		free(map->maze);
	free(map);
}
