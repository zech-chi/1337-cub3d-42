/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:18:50 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/11 04:04:55 by zech-chi         ###   ########.fr       */
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

mlx_image_t	*ft_get_image2(t_cub *cub, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_free_data(cub);
		ft_putstr_fd("Failed to open : ", 2, 0, RED);
		ft_putstr_fd(path, 2, 1, RED);
		free(path);
		exit(1);
	}
	image = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	ft_check_last_frame(t_cub *cub, int size)
{
	if (cub->mlx.index_weapon > size)
	{
		cub->mlx.index_weapon = 0;
		if (!cub->mlx.reload)
			cub->mlx.weapon_magazin_index++;
		ft_draw_weapon_magazine(cub);
		ft_reset_weapon_event(cub);
		cub->mlx.init_state = true;
	}
}
