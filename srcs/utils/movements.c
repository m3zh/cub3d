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
				* SPEED * 2)][(int)game->player.posy] == '0')
			game->player.posx -= game->player.inity * SPEED;
		if (game->config.maze[(int)game->player.posx][(int)(game->player.posy
			+ game->player.initx * SPEED * 2)] == '0')
			game->player.posy += game->player.initx * SPEED;
	}
	if (game->move.right)
	{
		if (game->config.maze[(int)(game->player.posx + game->player.inity
				* SPEED * 2)][(int)game->player.posy] == '0')
			game->player.posx += game->player.inity * SPEED;
		if (game->config.maze[(int)game->player.posx][(int)(game->player.posy
			- game->player.initx * SPEED * 2)] == '0')
			game->player.posy -= game->player.initx * SPEED;
	}
}

void	move_backforwards(t_game *game)
{
	if (game->move.forw)
	{
		if (game->config.maze[(int)(game->player.posx + game->player.initx
				* SPEED * 2)][(int)game->player.posy] == '0')
			game->player.posx += game->player.initx * SPEED;
		if (game->config.maze[(int)(game->player.posx)]
			[(int)(game->player.posy + game->player.inity * SPEED * 2)] == '0')
			game->player.posy += game->player.inity * SPEED;
	}
	if (game->move.back)
	{
		if (game->config.maze[(int)(game->player.posx - game->player.initx
				* SPEED * 2)][(int)(game->player.posy)] == '0')
			game->player.posx -= game->player.initx * SPEED;
		if (game->config.maze[(int)(game->player.posx)]
			[(int)(game->player.posy - game->player.inity * SPEED * 2)] == '0')
			game->player.posy -= game->player.inity * SPEED;
	}
}

void	rotate_view(t_game *game, double dx, double px)
{
	if (game->move.rotright)
	{
		game->player.initx = game->player.initx * cos(-ROT / 2)
			- game->player.inity * sin(-ROT / 2);
		game->player.inity = dx * sin(-ROT / 2)
			+ game->player.inity * cos(-ROT / 2);
		game->player.planex = game->player.planex * cos(-ROT / 2)
			- game->player.planey * sin(-ROT / 2);
		game->player.planey = px * sin(-ROT / 2) + game->player.planey
			* cos(-ROT / 2);
	}
	if (game->move.rotleft)
	{
		game->player.initx = game->player.initx * cos(ROT / 2)
			- game->player.inity * sin(ROT / 2);
		game->player.inity = dx * sin(ROT / 2) + game->player.inity
			* cos(ROT / 2);
		game->player.planex = game->player.planex * cos(ROT / 2)
			- game->player.planey * sin(ROT / 2);
		game->player.planey = px * sin(ROT / 2) + game->player.planey
			* cos(ROT / 2);
	}
}
