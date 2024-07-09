/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:08:46 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/07 22:57:54 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_turn_left(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
	{
		cub->player.angle += cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->angle_minimap += cub->player.turn_speed;
		cub->angle_minimap = ft_periodic(cub->angle_minimap);
		cub->render = true;
	}
}

void	ft_turn_right(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
	{
		cub->player.angle -= cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->angle_minimap -= cub->player.turn_speed;
		cub->angle_minimap = ft_periodic(cub->angle_minimap);
		cub->render = true;
	}
}
