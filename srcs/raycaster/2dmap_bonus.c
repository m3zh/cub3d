/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 07:24:02 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/09 12:59:59 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_mapsprite(int x, int y, t_game *game, int color)
{
	int	dx;
	int	dy;

	dy = -1 + TILE / 3;
	while (++dy < TILE / 3 * 2)
	{
		dx = -1 + TILE / 3;
		while (++dx < TILE / 3 * 2)
			game->img.addr[game->winW * (dy + y) + (dx + x)] = color;
	}
}

static void	draw_player(t_game *game)
{
	int	dx;
	int	dy;
	int	pixel;

	dy = -1;
	while (++dy < PLAYER)
	{
		dx = -1;
		while (++dx < PLAYER)
		{
			pixel = game->winW * (int)(dy + game->player.posx * TILE)
				+ (int)(dx + game->player.posy * TILE);
			game->img.addr[pixel] = 0xFFFF00;
		}
	}	
}

static void	draw_ray(t_game *game)
{
	double	px;
	double	py;
	double	dx;
	double	dy;
	int		pixel;

	px = (int)TILE * game->player.posy + game->player.inity;
	py = (int)TILE * game->player.posx + game->player.initx;
	dx = 1;
	dy = 1;
	while (1)
	{
		dx += game->player.planex;
		dy += -game->player.planey;
		pixel = (int)(game->winW * floor(py + dy) + floor(px + dx));
		if (game->img.addr[pixel] == GRAY || game->img.addr[pixel] == CYAN)
			break ;
		game->img.addr[game->winW * (int)floor(py + dy)
			+ (int)floor(px + dx)] = YELLOW;
	}
}

static void	draw_tile(int x, int y, t_game *game, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (++dy < TILE)
	{
		dx = -1;
		while (++dx < TILE)
			game->img.addr[game->winW * (dy + y) + (dx + x)] = color;
	}
}

int	draw_2dmap(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->config.maze[++y])
	{
		x = -1;
		while (game->config.maze[y][++x])
		{
			if (game->config.maze[y][x] == '1')
				draw_tile(x * TILE, y * TILE, game, GRAY);
			else if (game->config.maze[y][x] != ' ')
				draw_tile(x * TILE, y * TILE, game, GREEN);
			if (game->config.maze[y][x] == '2')
				draw_mapsprite(x * TILE, y * TILE, game, CYAN);
		}
	}
	draw_player(game);
	draw_ray(game);
	return (0);
}
