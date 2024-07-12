/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:21 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/12 09:31:04 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
	cub->player.bobbing_amplitude = 15.0;
	cub->player.bobbing_frequency = 2.0;
	cub->player.bobbing_time = 0.0;
	cub->player.bobbing_speed = 0.1;
	cub->player.is_walking = false;
	cub->player.head_bobbing_offset = 0.0;
	cub->player.offeset_jump = 0;
	cub->player.jump = false;
	cub->player.amplitude_jump = 110;
	cub->player.frequency_jump = 0.2;
	ft_set_player_angle(cub);
}

void	ft_player_event(t_cub *cub)
{
	ft_walk_up(cub);
	ft_walk_down(cub);
	ft_walk_left(cub);
	ft_walk_right(cub);
	ft_look_up(cub);
	ft_look_down(cub);
	ft_turn_left(cub);
	ft_turn_right(cub);
	ft_jump(cub);
	ft_head_bobbing(cub);
}
