/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:00:15 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/27 18:33:55 by zech-chi         ###   ########.fr       */
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
	(void)cub;
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}


/// @brief this function is amazing
/// @param cub 
/// @param distance 
/// @param x 
/// @param angle 
void	ft_draw_walls(t_cub *cub, double distance, int x, double angle)
{
	int	wall_height;
	int	y;

	wall_height = (cub->pixel / (distance * cos(cub->player.rot_angle - angle))) * ((cub->pixel * cub->cols / 2) / tan(M_PI / 6)) * 210;
	// wall_height = distance - 500;
	y = cub->pixel * cub->rows - wall_height / 2;
	y = max(y, 0);
	for (int y1 = 0; y1 < y; y1++)
		mlx_put_pixel(cub->mlx.maze_img, x, y1, ft_pixel(0, 0, 100, 255));
	// printf("%d\n", wall_height);
	while (y < min(cub->pixel * cub->rows - wall_height / 2 + wall_height, cub->rows * cub->pixel * 2))
	{
		// if (y < 0 || x < 0 || x > cub->cols * cub->pixel * 2 || y > cub->rows * cub->pixel * 2)
		// {
		// 	y++;
		// 	continue;
		// }
		// mlx_put_pixel(cub->mlx.maze_img, x, y, ft_pixel(255, 255, 255, 255 * exp(-0.00002 * distance)));
		mlx_put_pixel(cub->mlx.maze_img, x, y, ft_pixel(255, 255, 255, 255));
		y++;
	}
	for (int y2 = y; y2 < cub->rows * cub->pixel * 2; y2++)
		mlx_put_pixel(cub->mlx.maze_img, x, y2, ft_pixel(100, 100, 0, 255));
}
