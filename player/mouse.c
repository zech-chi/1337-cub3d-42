/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:59:01 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/03 21:52:00 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	mouse_func(double xpos, double ypos, void *param)
{
	t_cub	*cub;

	cub = param;
	if (cub->mlx.status == MLX_MOUSE_NORMAL)
		return ;
	(void)ypos;
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
	if (xpos > (WINDOW_WIDTH / 2) + ZONE)
	{
		cub->player.angle -= TURN_SPEED;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
	}
	else if (xpos < (WINDOW_WIDTH / 2) - ZONE)
	{
		cub->player.angle += TURN_SPEED;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
	}
	mlx_set_mouse_pos(cub->mlx.mlx_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

void	ft_disable_mouse(t_cub *cub)
{
	mlx_set_cursor_mode(cub->mlx.mlx_ptr, MLX_MOUSE_NORMAL);
	cub->mlx.status = MLX_MOUSE_NORMAL;
}

void	ft_enable_mouse(t_cub *cub)
{
	mlx_set_cursor_mode(cub->mlx.mlx_ptr, MLX_MOUSE_HIDDEN);
	cub->mlx.status = MLX_MOUSE_HIDDEN;
}

void mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_cub *cub = param;
	(void)mods;
	if (action == MLX_PRESS)
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
			ft_enable_mouse(cub);
		if (button == MLX_MOUSE_BUTTON_RIGHT)
			ft_disable_mouse(cub);
	}
}


