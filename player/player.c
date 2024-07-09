/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:21 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/08 21:18:20 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

void	ft_player_init(t_cub *cub)
{
	int	r;
	int	c;

	r = cub->player.pr;
	c = cub->player.pc;
	cub->player.py = cub->pixel * (cub->player.pr + 0.5);
	cub->player.px = cub->pixel * (cub->player.pc + 0.5);
	cub->map[r][c] = '0';
	if (cub->player.sens == 'N')
		cub->player.angle = M_PI / 2;
	else if (cub->player.sens == 'W')
		cub->player.angle = M_PI;
	else if (cub->player.sens == 'E')
		cub->player.angle = 0;
	else if (cub->player.sens == 'S')
		cub->player.angle = (3 * M_PI) / 2;
	cub->player.walk_speed = WALK_SPEED;
	cub->player.turn_speed = TURN_SPEED;
	cub->player.bobbing_amplitude = 15.0;
	cub->player.bobbing_frequency = 2.0;
	cub->player.bobbing_time = 0.0;
	cub->player.bobbing_speed = 0.1;
	cub->player.is_walking = false;
	cub->player.head_bobbing_offset = 0.0;
}

void ft_update_head_bobbing(t_cub *cub)
{
	if (cub->player.is_walking) {
		cub->player.bobbing_time += cub->player.bobbing_speed;
		cub->player.head_bobbing_offset = sin(cub->player.bobbing_time * cub->player.bobbing_frequency) * cub->player.bobbing_amplitude;
		if (cub->player.head_bobbing_offset < 0)
			cub->player.head_bobbing_offset *= -1;
	} else {
		cub->player.bobbing_time = 0.0;
		cub->player.head_bobbing_offset = 0.0;
	}
}
void	ft_jump(t_cub *cub)
{
	int static	time;

	if (cub->player.jump)
	{
		if (time == 0)
			cub->horizon -= JUMP;
		time++;
		if ((time % 5) == 0)
			cub->render = true;
		if (time == 50)
		{
			cub->player.jump = false;
			cub->render = true;
			time = 0;
		}
	}
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_J))
	{
		if (cub->player.jump)
			return ;
		cub->horizon += JUMP;
		cub->player.jump = true;
		cub->render = true;
	}
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
	ft_update_head_bobbing(cub);
}
