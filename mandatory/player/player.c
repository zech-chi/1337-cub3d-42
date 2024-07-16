/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:21 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/11 17:39:07 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_set_player_angle(t_cub *cub)
{
	if (cub->player.sens == 'N')
		cub->player.angle = M_PI / 2;
	else if (cub->player.sens == 'W')
		cub->player.angle = M_PI;
	else if (cub->player.sens == 'E')
		cub->player.angle = 0;
	else if (cub->player.sens == 'S')
		cub->player.angle = (3 * M_PI) / 2;
}

void	ft_player_init(t_cub *cub)
{
	int	r;
	int	c;

	r = cub->player.pr;
	c = cub->player.pc;
	cub->player.py = cub->pixel * (cub->player.pr + 0.5);
	cub->player.px = cub->pixel * (cub->player.pc + 0.5);
	cub->map[r][c] = '0';
	cub->player.walk_speed = WALK_SPEED;
	cub->player.turn_speed = TURN_SPEED;
	ft_set_player_angle(cub);
}

void	ft_player_event(t_cub *cub)
{
	ft_walk_up(cub);
	ft_walk_down(cub);
	ft_walk_left(cub);
	ft_walk_right(cub);
	ft_turn_left(cub);
	ft_turn_right(cub);
}
