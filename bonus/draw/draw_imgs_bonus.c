/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:48:55 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:27:44 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	ft_update_a(int a)
{
	if (a <= 0)
		return (0);
	return (a);
}

void	ft_draw_img(t_cub *cub, int i, int y, mlx_image_t *img)
{
	t_color	color;
	int		j;
	float	distance;

	distance = cub->rays[i].distance;
	j = (cub->offset.y_offset * PIXEL + cub->offset.x_offset) * 4;
	color.r = img->pixels[j];
	color.g = img->pixels[j + 1];
	color.b = img->pixels[j + 2];
	color.a = img->pixels[j + 3];
	if (!cub->light_on)
		color.a *= exp(-0.0001 * distance);
	mlx_put_pixel(cub->mlx.maze_img, i, y, \
	ft_color(color.r, color.g, color.b, \
	ft_update_a(color.a)));
}
