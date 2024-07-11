/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:48:55 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 17:12:03 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	mlx_put_pixel(cub->mlx.maze_img, i, y, \
	ft_color(color.r, color.g, color.b, color.a));
}
