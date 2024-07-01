/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:48:55 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/01 13:05:09 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_update_a(int a)
{
	if (a <= 0)
		return (0);
	return (a);
}

void	ft_draw_img(t_cub *cub, int x, int y, float distance, mlx_image_t *img)
{
	t_color color;
	int		j;

	j = (cub->offset.y_offset * PIXEL + cub->offset.x_offset) * 4;

	color.r = img->pixels[j];
	color.g = img->pixels[j + 1];
	color.b = img->pixels[j + 2];
	color.a = img->pixels[j + 3];
	mlx_put_pixel(cub->mlx.maze_img, x, y, \
	ft_color(color.r, color.g, color.b, \
	ft_update_a(color.a * exp(-0.0001 * distance))));
}