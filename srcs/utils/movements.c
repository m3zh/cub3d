/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:14:11 by mlazzare          #+#    #+#             */
/*   Updated: 2021/06/07 07:47:08 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_leftright(t_game *game)
{
	if (game->move.left)
	{
		if (game->config.maze[(int)(game->player.posx - game->player.inity
				* SPEED)][(int)game->player.posy] == '0')
			game->player.posx -= game->player.inity * SPEED;
		if (game->config.maze[(int)game->player.posx][(int)(game->player.posy
			+ game->player.initx * SPEED)] == '0')
			game->player.posy += game->player.initx * SPEED;
	}
	if (game->move.right)
	{
		if (game->config.maze[(int)(game->player.posx + game->player.inity
				* SPEED)][(int)game->player.posy] == '0')
			game->player.posx += game->player.inity * SPEED;
		if (game->config.maze[(int)game->player.posx][(int)(game->player.posy
			- game->player.initx * SPEED)] == '0')
			game->player.posy -= game->player.initx * SPEED;
	}
}

void	move_backforwards(t_game *game)
{
	if (game->move.forw)
	{
		if (game->config.maze[(int)(game->player.posx + game->player.initx
				* SPEED + 0.1)][(int)game->player.posy] == '0')
			game->player.posx += game->player.initx * SPEED;
		if (game->config.maze[(int)(game->player.posx)]
			[(int)(game->player.posy + game->player.inity * SPEED)] == '0')
			game->player.posy += game->player.inity * SPEED;
	}
	if (game->move.back)
	{
		if (game->config.maze[(int)(game->player.posx - game->player.initx
				* SPEED + 0.1)][(int)(game->player.posy)] == '0')
			game->player.posx -= game->player.initx * SPEED;
		if (game->config.maze[(int)(game->player.posx)]
			[(int)(game->player.posy - game->player.inity * SPEED)] == '0')
			game->player.posy -= game->player.inity * SPEED;
	}
}

void	rotate_view(t_game *game)
{
	double	dx;
	double	px;

	dx = game->player.initx;
	px = game->player.planex;
	if (game->move.rotright)
	{
		game->player.initx = game->player.initx * cos(-ROT)
			- game->player.inity * sin(-ROT);
		game->player.inity = dx * sin(-ROT)
			+ game->player.inity * cos(-ROT);
		game->player.planex = game->player.planex * cos(-ROT)
			- game->player.planey * sin(-ROT);
		game->player.planey = px * sin(-ROT) + game->player.planey * cos(-ROT);
	}
	if (game->move.rotleft)
	{
		game->player.initx = game->player.initx * cos(ROT)
			- game->player.inity * sin(ROT);
		game->player.inity = dx * sin(ROT) + game->player.inity * cos(ROT);
		game->player.planex = game->player.planex * cos(ROT)
			- game->player.planey * sin(ROT);
		game->player.planey = px * sin(ROT) + game->player.planey * cos(ROT);
	}
}
