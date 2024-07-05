/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:13:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/05 12:11:29 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_reset_weapon_event(t_cub *cub)
{
	cub->mlx.init_state = false;
	cub->mlx.normal_shoot1 = false;
	cub->mlx.normal_shoot2 = false;
	cub->mlx.zome_shoot1 = false;
	cub->mlx.zome_shoot2 = false;
	cub->mlx.walk = false;
	cub->mlx.reload = false;
}

bool	ft_there_is_active_event(t_cub *cub)
{
	return (cub->mlx.normal_shoot1 || cub->mlx.normal_shoot2 || \
	cub->mlx.zome_shoot1 || cub->mlx.zome_shoot2 || cub->mlx.walk \
	|| cub->mlx.reload);
}

void	ft_weapon_event(t_cub *cub)
{
	if (ft_there_is_active_event(cub))
		return ;
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_1))
	{
		ft_reset_weapon_event(cub);
		cub->mlx.normal_shoot1 = true;
	}
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_R))
	{
		ft_reset_weapon_event(cub);
		cub->mlx.reload = true;
	}
}

mlx_image_t	*ft_play_init_state(t_cub *cub)
{
	char			*name;
	mlx_texture_t	*texture;
	mlx_image_t		*cur_img;

	name = ft_strdup(PATH_WEAPONS_INIT_STATE);
	texture = mlx_load_png(name);
	free(name);
	cur_img = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_image_to_window(cub->mlx.mlx_ptr, cur_img, 0, 0);
	return (cur_img);
}

mlx_image_t	*ft_play_weapon_status(t_cub *cub, int size, bool *state, char *path)
{
	char			*name;
	mlx_texture_t	*texture;
	mlx_image_t		*cur_img;
	static int		index;

	name = ft_strjoin(ft_strdup(path), ft_itoa(index));
	name = ft_strjoin(name, ft_strdup(PNG));
	texture = mlx_load_png(name);
	cur_img = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_image_to_window(cub->mlx.mlx_ptr, cur_img, 0, 0);
	free(name);
	index++;
	if (index > size)
	{
		index = 0;
		(*state) = false;
		cub->mlx.init_state = true;
	}
	return (cur_img);
}
