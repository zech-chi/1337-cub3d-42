/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:09:33 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:30:57 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_look_up(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_UP))
	{
		if (cub->horizon < HORIZON)
		{
			(cub->horizon) += LOOK_SPEED;
			cub->render = true;
		}
	}
}

void	ft_look_down(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_DOWN))
	{
		if (cub->horizon > -(HORIZON))
		{
			(cub->horizon) -= LOOK_SPEED;
			cub->render = true;
		}
	}
}
