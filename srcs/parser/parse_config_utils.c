/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:40:08 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 12:59:56 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_cf(char *line)
{
	return ((line[0] == 'F' || line[0] == 'C')
		&& (line[1] == ' ' || ft_isdigit(line[1])));
}

void	update_cf(t_map *map, char c)
{
	if (c == 'F')
		map->f_check = 1;
	else if (c == 'C')
		map->c_check = 1;
}

int	skip_space(char *l, int i)
{
	while (l[i] && ft_isspace(l[i]))
		i++;
	return (i);
}

void	update_map(t_map *map)
{
	map->complete++;
	free(map->trim);
	map->trim = NULL;
}

void	free_line(t_map *map)
{
	if (map->line)
		free(map->line);
	map->line = NULL;
}
