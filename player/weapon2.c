/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:18:50 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/10 22:01:03 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	ft_there_is_active_event(t_cub *cub)
{
	return (cub->mlx.normal_shoot1 || cub->mlx.zome_shoot1 || cub->mlx.walk \
	|| cub->mlx.reload);
}

void	ft_reset_weapon_event(t_cub *cub)
{
	cub->mlx.init_state = false;
	cub->mlx.normal_shoot1 = false;
	cub->mlx.zome_shoot1 = false;
	cub->mlx.walk = false;
	cub->mlx.reload = false;
}

void	ft_weapon_event(t_cub *cub)
{
	if (ft_there_is_active_event(cub))
		return ;
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_1))
	{
		mlx_set_cursor_mode(cub->mlx.mlx_ptr, MLX_MOUSE_NORMAL);
		cub->mlx.status = MLX_MOUSE_NORMAL;
	}
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_R))
	{
		ft_reset_weapon_event(cub);
		cub->mlx.reload = true;
	}
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_2))
	{
		mlx_set_cursor_mode(cub->mlx.mlx_ptr, MLX_MOUSE_HIDDEN);
		cub->mlx.status = MLX_MOUSE_HIDDEN;
	}
}
