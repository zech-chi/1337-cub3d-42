/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:08:46 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:31:07 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_turn_left(t_cub *cub)
{
	int	x;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
	{
		x = cub->mlx.sky->instances[0].x + 5;
		if (x < 5)
			cub->mlx.sky->instances[0].x = x;
		else
			cub->mlx.sky->instances[0].x = -720;
		cub->player.angle += cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->angle_minimap += cub->player.turn_speed;
		cub->angle_minimap = ft_periodic(cub->angle_minimap);
		cub->render = true;
	}
}

void	ft_turn_right(t_cub *cub)
{
	int	x;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
	{
		x = cub->mlx.sky->instances[0].x - 5;
		if (x > -720)
			cub->mlx.sky->instances[0].x = x;
		else
			cub->mlx.sky->instances[0].x = 0;
		cub->player.angle -= cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->angle_minimap -= cub->player.turn_speed;
		cub->angle_minimap = ft_periodic(cub->angle_minimap);
		cub->render = true;
	}
}
