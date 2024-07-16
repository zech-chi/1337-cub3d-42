/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:46:26 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 11:15:40 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_set_offeset(t_cub *cub, int i)
{
	if (!cub->rays[i].was_vertical)
		cub->offset.x_offset = (int)cub->rays[i].hitx % PIXEL;
	else
		cub->offset.x_offset = (int)cub->rays[i].hity % PIXEL;
}

static void	ft_draw_floor(t_cub *cub, int i, int bottom_pixel)
{
	int	y;

	y = bottom_pixel;
	while (y < WINDOW_HEIGHT)
	{
		mlx_put_pixel(cub->mlx.maze_img, i, y, \
		ft_color(cub->cf[0], cub->cf[1], cub->cf[2], 255));
		y++;
	}
}

static void	ft_draw_correct_wall(t_cub *cub, int i, int y)
{
	if (cub->rays[i].found_door)
		ft_draw_img(cub, i, y, cub->mlx.door);
	else if (cub->rays[i].found_shoot_target)
		ft_draw_img(cub, i, y, cub->mlx.shoot_target);
	else if (!cub->rays[i].was_vertical && cub->rays[i].up)
		ft_draw_img(cub, i, y, cub->mlx.no_img);
	else if (!cub->rays[i].was_vertical && cub->rays[i].down)
		ft_draw_img(cub, i, y, cub->mlx.so_img);
	else if (cub->rays[i].right)
		ft_draw_img(cub, i, y, cub->mlx.ea_img);
	else
		ft_draw_img(cub, i, y, cub->mlx.we_img);
}

static void	ft_draw_walls(t_cub *cub, int i)
{
	int	wall_height;
	int	y;
	int	top_pixel;
	int	bottom_pixel;
	int	distance_from_top;

	wall_height = (cub->pixel / (cub->rays[i].distance * cos(cub->player.angle \
	- cub->rays[i].angle))) * ((WINDOW_WIDTH / 2) / tan(M_PI / 6));
	top_pixel = ft_max_d(WINDOW_HEIGHT / 2 - wall_height / 2 + cub->horizon + \
	cub->player.head_bobbing_offset + cub->player.offeset_jump, 0);
	bottom_pixel = ft_min(WINDOW_HEIGHT / 2 + wall_height / 2 + cub->horizon + \
	cub->player.head_bobbing_offset + cub->player.offeset_jump, WINDOW_HEIGHT);
	ft_set_offeset(cub, i);
	y = top_pixel;
	while (y < bottom_pixel)
	{
		distance_from_top = y - cub->horizon - cub->player.head_bobbing_offset \
		- cub->player.offeset_jump - WINDOW_HEIGHT / 2 + wall_height / 2;
		cub->offset.y_offset = (distance_from_top) * \
		((float)PIXEL / wall_height);
		mlx_put_pixel(cub->mlx.canva, i, y, ft_color(0, 0, 0, 255));
		ft_draw_correct_wall(cub, i, y);
		y++;
	}
	ft_draw_floor(cub, i, bottom_pixel);
}

void	ft_render_walls(t_cub *cub)
{
	int	i;

	i = 1;
	while (i < NUMBER_RAYS - 1)
	{
		if (cub->rays[i - 1].was_vertical == cub->rays[i + 1].was_vertical)
			cub->rays[i].was_vertical = cub->rays[i - 1].was_vertical;
		i++;
	}
	i = 0;
	while (i < NUMBER_RAYS)
	{
		ft_draw_walls(cub, i);
		i++;
	}
}
