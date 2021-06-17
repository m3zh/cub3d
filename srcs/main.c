/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:13:37 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/06 16:22:38 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	initialise_map(t_map *map)
{
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->s = 0;
	map->maze = (char **)malloc(sizeof(char *) * FILESIZE);
	*map->maze = NULL;
	map->line = 0;
	map->trim = 0;
	map->idx = 0;
	map->x = -1;
	map->y = -1;
	map->start_wall = -1;
	map->end_wall = -1;
	map->sprites = 0;
	map->f_check = 0;
	map->c_check = 0;
	map->complete = 0;
	map->end = 0;
}

static void	check_extension(char *path, t_map *map)
{
	int	l;

	l = ft_strlen(path);
	if (ft_strcmp(&path[l - 4], ".cub"))
	{
		get_error('e');
		free_map(map);
		exit(0);
	}
}

static int	boot_cub3d(char **av)
{
	t_map	*map;
	int		game;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
	initialise_map(map);
	check_extension(av[1], map);
	game = read_map(map, av);
	if (game < 0)
	{
		printf("An error occured while reading the map.\n");
		free_parse(map);
		return (0);
	}
	start_game(*map);
	free_map(map);
	return (1);
}

int	main(int ac, char **av)

{
	if (ac != 2)
		printf("Invalid number of arguments.\nRetry.");
	else
		boot_cub3d(av);
	return (0);
}
