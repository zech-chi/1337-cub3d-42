/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:07:51 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/11 17:09:12 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_reset_walls(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			mlx_put_pixel(cub->mlx.maze_img, x, y, ft_color(255, 255, 255, 0));
		}
	}
}

void	ft_close_win_event(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx.mlx_ptr);
}

void	ft_render(void *param)
{
	t_cub	*cub;

	cub = param;
	ft_close_win_event(cub);
	ft_player_event(cub);
	if (cub->render)
	{
		ft_reset_walls(cub);
		ft_rays(cub);
		ft_render_walls(cub);
	}
	cub->render = false;
	cub->player.is_walking = false;
}

void	ft_build_maze(t_cub *cub)
{
	ft_mlx_init(cub);
	ft_load_img(cub);
	ft_mlx_image_to_window(cub, cub->mlx.maze_img, 0, 0);
	mlx_loop_hook(cub->mlx.mlx_ptr, ft_render, cub);
	mlx_loop(cub->mlx.mlx_ptr);
}
