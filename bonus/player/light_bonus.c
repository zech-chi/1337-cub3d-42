/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:46:22 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:30:54 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_light_event(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_O))
	{
		cub->light_on = true;
		cub->render = true;
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_F))
	{
		cub->light_on = false;
		cub->render = true;
	}
}
