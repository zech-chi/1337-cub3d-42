/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:59:01 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:07:17 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_check_look(t_cub *cub, double ypos)
{
	if (ypos > (WINDOW_HEIGHT / 2) + ZONE)
	{
		if (cub->horizon > -(HORIZON))
		{
			(cub->horizon) -= LOOK_SPEED;
			cub->render = true;
		}
	}
	else if (ypos < (WINDOW_HEIGHT / 2) - ZONE)
	{
		if (cub->horizon < HORIZON)
		{
			(cub->horizon) += LOOK_SPEED;
			cub->render = true;
		}
	}
}

void static	ft_update_data_player(t_cub *cub, bool turn_right)
{
	int	x;

	if (turn_right)
	{
		x = cub->mlx.sky->instances[0].x - 5;
		if (x > -720)
			cub->mlx.sky->instances[0].x = x;
		else
			cub->mlx.sky->instances[0].x = 0;
		cub->player.angle -= TURN_SPEED;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
	}
	else
	{
		x = cub->mlx.sky->instances[0].x + 5;
		if (x < 5)
			cub->mlx.sky->instances[0].x = x;
		else
			cub->mlx.sky->instances[0].x = -720;
		cub->player.angle += TURN_SPEED;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
	}
}

void	ft_check_turn(t_cub *cub, double xpos)
{
	pthread_mutex_lock(&(cub->thread.mtx_protect));
	if (cub->mlx.reload || cub->mlx.zome_shoot1 || cub->mlx.normal_shoot1)
	{
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
		return ;
	}
	pthread_mutex_unlock(&(cub->thread.mtx_protect));
	if (xpos > (WINDOW_WIDTH / 2) + ZONE)
		ft_update_data_player(cub, true);
	else if (xpos < (WINDOW_WIDTH / 2) - ZONE)
		ft_update_data_player(cub, false);
}

void	mouse_func(double xpos, double ypos, void *param)
{
	t_cub	*cub;

	cub = param;
	if (cub->mlx.status == MLX_MOUSE_NORMAL)
		return ;
	ft_check_look(cub, ypos);
	ft_check_turn(cub, xpos);
	mlx_set_mouse_pos(cub->mlx.mlx_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

void	mouse_hook(mouse_key_t button, action_t action, \
modifier_key_t mods, void *param)
{
	t_cub	*cub;

	cub = param;
	(void)mods;
	pthread_mutex_lock(&(cub->thread.mtx_protect));
	if (ft_there_is_active_event(cub))
	{
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
		return ;
	}
	if (action == MLX_PRESS)
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
		{
			ft_reset_weapon_event(cub);
			cub->mlx.normal_shoot1 = true;
		}
		if (button == MLX_MOUSE_BUTTON_RIGHT)
		{
			ft_reset_weapon_event(cub);
			cub->mlx.zome_shoot1 = true;
		}
	}
	pthread_mutex_unlock(&(cub->thread.mtx_protect));
}
