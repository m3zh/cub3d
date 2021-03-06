/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maze_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:40:08 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 13:03:54 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	not_walled(int pos, t_map *map)
{
	if (pos <= map->end_wall)
		return (map->maze[map->idx - 1][pos] == '1'
			|| ft_isspace(map->maze[map->idx - 1][pos]));
	return (1);
}

static int	not_map(int y, t_map *map)
{
	return (y > (int)ft_strlen(map->maze[map->idx - 1]));
}

int	check_maze(t_map *map, char *l, int y)
{
	if (l[y] == '2')
		map->sprites++;
	if (ft_ismaze(l[y]) && (not_map(y, map)
			|| ft_isspace(map->maze[map->idx - 1][y])))
		return (-1);
	return (y + 1);
}

int	map_checked(t_map *map)
{
	if ((!BNS && map->complete == 6)
		|| (BNS && map->complete == 7))
		return (1);
	return (0);
}

int	check_map(t_map *map, int err)
{
	if (err)
		return (-1);
	if (!BNS && map->sprites > 0)
		return (-get_error('m'));
	if ((!BNS && map->complete != 6) || (BNS && map->complete != 7))
		return (-get_error('f'));
	if (map->x < 0)
		return (-get_error('p'));
	return (1);
}
