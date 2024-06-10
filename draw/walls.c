/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:07:51 by zelabbas          #+#    #+#             */
/*   Updated: 2024/06/10 12:26:10 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int32_t ft_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_draw_rectangle(t_cub *cub, int r, int c, uint32_t color)
{
	for (int i = r; i < r + cub->pixel; i++)
	{
		for (int j = c; j < c + cub->pixel; j++)
		{
			mlx_put_pixel(cub->mlx.maze_img, j, i, color);
		}
	}
}

void	ft_render_map(t_cub *cub)
{
	for (int r = 0; r < cub->rows; r++)
	{
		for (int c = 0; c < cub->cols; c++)
		{
			if (cub->map[r][c] == ' ')
				ft_draw_rectangle(cub, cub->pixel * r , cub->pixel * c, ft_color(0, 0, 0,255));
			else if (cub->map[r][c] == '1')
				ft_draw_rectangle(cub, cub->pixel * r , cub->pixel * c , ft_color(255, 255, 255,255));
			else if (cub->map[r][c] == '0')
				ft_draw_rectangle(cub, cub->pixel * r , cub->pixel * c , ft_color(0,0,0,255));
		}
	}
}


void	ft_render(void *param)
{
	t_cub	*cub;

	cub = param;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx.mlx_ptr);
	ft_player_event(cub);
	if (!cub->render)
		return ;
	ft_render_map(cub);
	ft_render_player(cub);
	cub->render = false;
}

void	ft_build_maze(t_cub *cub)
{
	// if (!(cub->mlx.mlx_ptr = mlx_init(cub->window_width, cub->window_height, "ziko^2", false)))
	// {
	// 	perror(mlx_strerror(mlx_errno));
	// 	return ;
	// }
	if (!(cub->mlx.mlx_ptr = mlx_init(cub->cols * cub->pixel, cub->rows * cub->pixel, "ziko^2", false)))
	{
		perror(mlx_strerror(mlx_errno));
		return ;
	}
	// cub->mlx.maze_img = mlx_new_image(cub->mlx.mlx_ptr, cub->window_width, cub->window_height);
	// if (!cub->mlx.maze_img)
	// {
	// 	perror(mlx_strerror(mlx_errno));
	// 	return;
	// }
	cub->mlx.maze_img = mlx_new_image(cub->mlx.mlx_ptr, cub->cols * cub->pixel, cub->rows * cub->pixel);
	if (!cub->mlx.maze_img)
	{
		perror(mlx_strerror(mlx_errno));
		return;
	}
	mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.maze_img, 0, 0);
	mlx_loop_hook(cub->mlx.mlx_ptr, ft_render, cub);
	mlx_loop(cub->mlx.mlx_ptr);
}