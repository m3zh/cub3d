/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 07:43:16 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/11 07:30:55 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	wrong_line_setup(t_map *map)
{
	if (!map->line)
		return (get_error('l', map));
	map->trim = trimspaces(map->line);
	if (!map->trim)
		return (get_error('l', map));
	return (0);
}

static int	map_checked(t_map *map)
{
	if ((!BNS && map->complete == 6)
		|| (BNS && map->complete == 7))
		return (1);
	return (0);
}

static int	fill_map(t_map *map)
{
	if (wrong_line_setup(map))
		return (1);
	if (map->trim[0] == 'N' && !map->no)
		return (get_path(map, map->trim));
	else if (map->trim[0] == 'S' && map->trim[1] == 'O' && !map->so)
		return (get_path(map, map->trim));
	else if (map->trim[0] == 'W' && !map->we)
		return (get_path(map, map->trim));
	else if (map->trim[0] == 'E' && !map->ea)
		return (get_path(map, map->trim));
	else if (BNS && map->trim[0] == 'S' && map->trim[1] != 'O' && !map->s)
		return (get_sprite_path(map, map->trim));
	else if (map->trim[0] == 'C' && !map->c_check)
		return (get_comma_value(map, map->c, map->line));
	else if (map->trim[0] == 'F' && !map->f_check)
		return (get_comma_value(map, map->f, map->line));
	else if (map_checked(map))
		return (get_maze(map));
	else
	{
		free(map->trim);
		map->trim = NULL;
		return (get_error('x', map));
	}
	return (0);
}

int	read_map(t_map *map, char **av)
{
	int		fd;
	int		err;

	err = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		get_error('o', map);
	while (fd && (get_next_line(fd, &map->line, err) > 0))
	{
		if (!err && ft_strcmp(map->line, ""))
			err = fill_map(map);
		if (!ft_strcmp(map->line, "") && map->idx > 0)
			err = get_error('m', map);
		free(map->line);
		map->line = NULL;
	}
	if (err)
		return (-1);
	if ((!BNS && map->complete != 6) || (BNS && map->complete != 7))
		return (-get_error('i', map));
	else if (map->x < 0)
		return (-get_error('p', map));
	if (check_bottom_wall(map, map->maze[map->idx - 1]))
		return (-1);
	if (!err)
		return (close(fd));
	return (-1);
}
