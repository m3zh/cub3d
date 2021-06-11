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
	if (map->maze[map->idx - 1][pos] != '1'
		|| map->maze[map->idx - 1][pos] != ' ')
		return (0);
	return (1);
}

int	check_spaces(int pos, t_map *map, char *l)
{
	while (l[pos] && pos < map->end_wall)
	{
		while (l[pos] && l[pos] == ' ' && not_walled(pos, map))
			pos++;
		if (l[pos] != '1')
			return (-1);
		else
			break ;
	}
	return (pos + 1);
}

int	check_if_walled(t_map *map, char *l)
{
	int	i;

	i = -1;
	while (l[++i])
	{
		if (l[i] == '0' && map->maze[0][i] != '1')
			return (get_error('w'));
	}
	return (0);
}

int	check_maze(t_map *map, char *l, int y)
{
	while (l[y] && (l[y] == '0' || l[y] == '2' || l[y] == '1'))
	{
		if (l[y] == '2')
			map->sprites++;
		y++;
	}
	return (y);
}
