/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:40:59 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 04:29:26 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mlx_init(t_cub *cub)
{
	cub->mlx.mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WIN_NAME,
			false);
	if (!cub->mlx.mlx_ptr)
	{
		ft_putstr_fd("Failed to init mlx", 2, 1, RED);
		ft_free_data(cub);
		exit(1);
	}
}

void	ft_load_img(t_cub *cub)
{
	cub->mlx.ea_img = ft_get_image(cub, cub->ea);
	cub->mlx.no_img = ft_get_image(cub, cub->no);
	cub->mlx.we_img = ft_get_image(cub, cub->we);
	cub->mlx.so_img = ft_get_image(cub, cub->so);
	cub->mlx.target = ft_get_image(cub, PATH_TARGET);
	cub->mlx.door = ft_get_image(cub, PATH_DOOR);
	cub->mlx.black = ft_get_image(cub, PATH_BLACK);
	cub->mlx.weapon_magazin = ft_get_image(cub, PATH_WEAPON_MAGAZINE_0);
	cub->mlx.circle = ft_get_image(cub, PATH_CIRCLE);
	cub->mlx.background_start = ft_get_image(cub, PATH_GAME_START_0);
	cub->mlx.sky = ft_get_image(cub, PATH_SKY);
	cub->mlx.shoot_target = ft_get_image(cub, PATH_SHOOT_TARGET);
	cub->mlx.canva = ft_mlx_new_image(cub, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub->mlx.maze_img = ft_mlx_new_image(cub, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub->mlx.minimap = ft_mlx_new_image(cub, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	cub->mlx.player_rays = ft_mlx_new_image(cub, MINIMAP_WIDTH, MINIMAP_HEIGHT);
}

void	ft_mlx_image_to_window(t_cub *cub, mlx_image_t *img, int x, int y)
{
	int	check;

	check = mlx_image_to_window(cub->mlx.mlx_ptr, img, x, y);
	if (check == -1)
	{
		ft_putstr_fd("Failed to put image to window", 2, 1, RED);
		ft_free_data(cub);
		exit(1);
	}
}

mlx_image_t	*ft_get_image(t_cub *cub, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Failed to open : ", 2, 0, RED);
		ft_putstr_fd(path, 2, 1, RED);
		ft_free_data(cub);
		exit(1);
	}
	image = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	mlx_delete_texture(texture);
	return (image);
}

mlx_image_t	*ft_mlx_new_image(t_cub *cub, uint32_t width, uint32_t height)
{
	mlx_image_t	*image;

	image = mlx_new_image(cub->mlx.mlx_ptr, width, height);
	if (!image)
	{
		ft_putstr_fd("Failed to create image", 2, 1, RED);
		ft_free_data(cub);
		exit(1);
	}
	return (image);
}
