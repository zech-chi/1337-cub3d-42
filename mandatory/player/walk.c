/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:06:53 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 17:39:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_walk_up(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W))
	{
		if (!ft_can_walk_up(cub))
			return ;
		a = cub->player.walk_speed * cos(cub->player.angle);
		b = -1 * cub->player.walk_speed * sin(cub->player.angle);
		if (!ft_iswall2(cub, cub->player.px + N_STEPS * a, \
		cub->player.py + N_STEPS * b, cub->player.angle))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}

void	ft_walk_down(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_S))
	{
		if (!ft_can_walk_down2(cub))
			return ;
		a = -1 * cub->player.walk_speed * cos(cub->player.angle);
		b = cub->player.walk_speed * sin(cub->player.angle);
		if (ft_can_walk_down(cub, a, b))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}

void	ft_walk_left(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_A))
	{
		a = cub->player.walk_speed * cos(cub->player.angle + M_PI_2);
		b = -1 * cub->player.walk_speed * sin(cub->player.angle + M_PI_2);
		if (!ft_iswall2(cub, cub->player.px + N_STEPS * a, \
		cub->player.py + N_STEPS * b, cub->player.angle + M_PI_2))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}

void	ft_walk_right(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_D))
	{
		a = cub->player.walk_speed * cos(cub->player.angle - M_PI_2);
		b = -1 * cub->player.walk_speed * sin(cub->player.angle - M_PI_2);
		if (!ft_iswall2(cub, cub->player.px + N_STEPS * a, \
		cub->player.py + N_STEPS * b, cub->player.angle - M_PI_2))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}
