/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:13:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 14:07:17 by zech-chi         ###   ########.fr       */
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

void	ft_set_weapon_normal(t_cub *cub)
{
	ft_reset_weapon_event(cub);
	cub->mlx.init_state = true;
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
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_2))
	{
		ft_reset_weapon_event(cub);
		cub->mlx.normal_shoot2 = true;
	}
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_3))
	{
		ft_reset_weapon_event(cub);
		cub->mlx.zome_shoot1 = true;
	}
	else if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_4))
	{
		ft_reset_weapon_event(cub);
		cub->mlx.zome_shoot2 = true;
	}
}

void	ft_draw_weapon_magazine(t_cub *cub)
{
	char			*name;
	mlx_texture_t	*texture;

	name = NULL;
	name = ft_strjoin(ft_strdup(PATH_WEAPON_MAGAZINE), ft_itoa(cub->mlx.weapon_magazin_index));
	name = ft_strjoin(name, ft_strdup(PNG));
	texture = mlx_load_png(name);
	if (cub->mlx.weapon_magazin)
		mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.weapon_magazin);
	cub->mlx.weapon_magazin = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.weapon_magazin, WEAPON_MAGAZIN_X, WEAPON_MAGAZIN_Y);
	free(name);
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

mlx_image_t	*ft_play_weapon_status(t_cub *cub, int size, char *path)
{
	char			*name;
	mlx_texture_t	*texture;
	mlx_image_t		*cur_img;
	static int		index;

	if (index == 14)
	{
		if (cub->mlx.reload)
			ft_play_action_sound(cub);
	}
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
		if (!cub->mlx.reload)
			cub->mlx.weapon_magazin_index++;
		if (cub->mlx.normal_shoot2 || cub->mlx.zome_shoot2)
			cub->mlx.weapon_magazin_index = 9;
		printf("%d\n", cub->mlx.weapon_magazin_index);
		ft_draw_weapon_magazine(cub);
		ft_set_weapon_normal(cub);
	}
	return (cur_img);
}
