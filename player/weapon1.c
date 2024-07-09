/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:13:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 20:35:56 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_draw_weapon_magazine(t_cub *cub)
{
	char			*name;
	mlx_texture_t	*texture;

	name = NULL;
	name = ft_strjoin(ft_strdup(PATH_WEAPON_MAGAZINE), \
	ft_itoa(cub->mlx.weapon_magazin_index));
	name = ft_strjoin(name, ft_strdup(PNG));
	texture = mlx_load_png(name);
	if (cub->mlx.weapon_magazin)
		mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.weapon_magazin);
	cub->mlx.weapon_magazin = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.weapon_magazin, \
	WEAPON_MAGAZIN_X, WEAPON_MAGAZIN_Y);
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

	// ft_play_sound(cub, index);
	name = ft_strjoin(ft_strdup(path), ft_itoa(cub->mlx.index_weapon));
	name = ft_strjoin(name, ft_strdup(PNG));
	texture = mlx_load_png(name);
	cur_img = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_image_to_window(cub->mlx.mlx_ptr, cur_img, 0, 0);
	free(name);
	(cub->mlx.index_weapon)++;
	if (cub->mlx.index_weapon > size)
	{
		cub->mlx.index_weapon = 0;
		if (!cub->mlx.reload)
			cub->mlx.weapon_magazin_index++;
		printf("%d\n", cub->mlx.weapon_magazin_index);
		ft_draw_weapon_magazine(cub);
		ft_reset_weapon_event(cub);
		cub->mlx.init_state = true;
	}
	return (cur_img);
}
