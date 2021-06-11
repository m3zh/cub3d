/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:55:39 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 07:32:26 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_colors(t_map *map, char c)
{
	if (c == 'c')
		return (map->c[2] << 16 | map->c[1] << 8 | map->c[0]);
	return (map->f[2] << 16 | map->f[1] << 8 | map->f[0]);
}
