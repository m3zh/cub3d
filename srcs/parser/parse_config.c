/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:40:08 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/11 07:31:36 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_direction(t_map *map, char *li, int i)
{
	if (li[0] == 'N')
		map->no = ft_strdup(&li[i]);
	else if (li[0] == 'S')
		map->so = ft_strdup(&li[i]);
	else if (li[0] == 'W')
		map->we = ft_strdup(&li[i]);
	else if (li[0] == 'E')
		map->ea = ft_strdup(&li[i]);
}

int	get_path(t_map *map, char *line)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (!(ft_isdirection(line, i)))
		return (get_error('d', map));
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	if (!(line[i] == '.' && line[i + 1] == '/'))
		return (get_error('t', map));
	start = i;
	i += 2;
	while (line[i] && ft_isalpha(line[i]))
		i++;
	if (line[i] == '/')
		i++;
	while (line[i] && ft_isalpha(line[i]))
		i++;
	get_direction(map, line, start);
	map->complete++;
	free(map->trim);
	map->trim = NULL;
	return (0);
}

int	get_sprite_path(t_map *map, char *line)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (!(line[i] == 'S' && (line[i + 1] == ' ' || ft_isdigit(line[i + 1]))))
		return (get_error('d', map));
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	if (!(line[i] == '.' && line[i + 1] == '/'))
		return (get_error('r', map));
	start = i;
	i += 2;
	while (line[i] && ft_isalpha(line[i]))
		i++;
	if (line[i] == '/')
		i++;
	while (line[i] && ft_isalpha(line[i]))
		i++;
	map->s = ft_strdup(&line[start]);
	map->complete++;
	free(map->trim);
	map->trim = NULL;
	return (0);
}

int	get_comma_value(t_map *map, int *s, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!check_cf(line))
		return (get_error('g', map));
	update_cf(map, line[i]);
	while (line[i++])
	{
		i = skip_space(line, i);
		if (!(ft_isdigit(line[i]) && ++j < 3))
			return (get_error('x', map));
		s[j] = ft_atoi(&line[i]);
		if (s[j] < 0 || s[j] > 255)
			return (get_error('g', map));
		i += ft_numlen(s[j]);
		i = skip_space(line, i);
		if (line[i] && line[i] != ',' && j != 2)
			return (get_error('g', map));
	}
	if (j != 2)
		return (get_error('g', map));
	map->complete++;
	free(map->trim);
	map->trim = NULL;
	return (0);
}
