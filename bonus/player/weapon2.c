/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:18:50 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/11 22:24:52 by zelabbas         ###   ########.fr       */
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
	pthread_mutex_lock(&(cub->thread.mtx_protect));
	if (ft_there_is_active_event(cub))
	{
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
		return ;
	}
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
	pthread_mutex_unlock(&(cub->thread.mtx_protect));
}

mlx_image_t	*ft_get_image2(t_cub *cub, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Failed to open : ", 2, 0, RED);
		ft_putstr_fd(path, 2, 1, RED);
		free(path);
		ft_free_data(cub);
		exit(1);
	}
	image = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	ft_check_last_frame(t_cub *cub, int size)
{
	int	check;

	check = 1;
	pthread_mutex_lock(&(cub->thread.mtx_protect));
	if (cub->mlx.index_weapon > size)
	{
		check = 0;
		cub->mlx.index_weapon = 0;
		if (!cub->mlx.reload)
			cub->mlx.weapon_magazin_index++;
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
		ft_draw_weapon_magazine(cub);
		ft_reset_weapon_event(cub);
		cub->mlx.init_state = true;
	}
	if (check)
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
}
