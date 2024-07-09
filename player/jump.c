/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:15:17 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/09 15:26:12 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static float	ft_calculate_jump(t_cub *cub, float x)
{
	return ((cub->player.amplitude_jump * sin(cub->player.frequency_jump * x)));
}

void	ft_jump(t_cub *cub)
{
	static float	time;

	if (cub->player.jump)
	{
		time += SPEED_JUMP;
		if (time <= _5PI)
		{
			cub->player.offeset_jump = ft_calculate_jump(cub, time);
			cub->render = true;
		}
		else
		{
			cub->player.jump = false;
			time = 0;
			cub->player.offeset_jump = 0;
		}
	}
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_J))
	{
		time += SPEED_JUMP;
		cub->player.offeset_jump = ft_calculate_jump(cub, time);
		cub->player.jump = true;
		cub->render = true;
	}
}
