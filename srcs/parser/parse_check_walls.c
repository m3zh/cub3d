/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:40:08 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 12:59:29 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_top_wall(t_map *map)
{
	int	i;
	int	e;

	i = 0;
	e = ft_strlen(map->line) - 1;
	while (map->line[i] && map->line[i] == ' ')
		i++;
	if (!(map->line[i] && map->line[i] == '1'))
		return (get_error('m'));
	map->start_wall = i;
	while (map->line[e] && map->line[e] == ' ')
		e--;
	if (!(map->line[e] && map->line[e] == '1'))
		return (get_error('m'));
	map->end_wall = e;
	while ((map->line[i] == '1' || map->line[i] == ' ') && i < e)
		i++;
	return (0);
}

int	check_walls(t_map *map, char *l)
{
	int	y;

	y = 0;
	while (l[y] && l[y] == ' ')
		y++;
	if (get_startwall(map, l, y))
		return (1);
	while (l[y] && l[y] == '1')
		y++;
	while (l[y])
	{
		y = check_maze(map, l, y);
		if (ft_isplayerpos(l[y]))
			y = get_playerpos(map, y);
		else if (l[y] == ' ' && l[y - 1] == '1')
			y = check_spaces(y, map, l);
		else if (l[y])
			y = -1;
		if (y == -1)
			return (get_error('w'));
	}
	return (get_endwall(map, l));
}

int	check_bottom_wall(t_map *map, char *l)
{
	int	i;
	int	e;

	i = 0;
	e = ft_strlen(l) - 1;
	while (l[i] && l[i] == ' ' && not_walled(i, map))
		i++;
	if (get_startwall(map, l, i))
		return (1);
	while (l[e] && l[e] == ' ')
		e--;
	if (l[e] && l[e] == '1')
		map->end_wall = e;
	else
		return (get_error('m'));
	while ((l[i] == '1' || l[i] == ' ') && i < e)
		i++;
	if (i != e)
		return (get_error('m'));
	return (0);
}
