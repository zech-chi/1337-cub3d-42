/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:00:15 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/08 20:45:03 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	ft_reset_walls(t_cub *cub)
{
	for (int y = 0; y < cub->rows * cub->pixel * 2; y++) {
		for (int x = 0; x < cub->cols * cub->pixel * 2; x++) {
			mlx_put_pixel(cub->mlx.maze_img, x, y, ft_pixel(255, 255, 255, 0));
		}
	}
}

void	ft_draw_walls(t_cub *cub, double distance, int x)
{
	int	wall_height;
	int	y;

	wall_height = (cub->pixel / distance) * ((cub->pixel * cub->cols) / tan(M_PI / 6)) * 30;
	// wall_height = distance - 500;
	y = cub->pixel * cub->rows - wall_height / 2;
	// printf("%d\n", wall_height);
	while (y < cub->pixel * cub->rows - wall_height / 2 + wall_height)
	{
		if (y < 0 || x < 0 || x > cub->cols * cub->pixel * 2 || y > cub->rows * cub->pixel * 2)
		{
			y++;
			continue;
		}
		mlx_put_pixel(cub->mlx.maze_img, x, y, ft_pixel(255, 255, 255, 255 * exp(-0.00009 * distance)));
		y++;
	}
}
