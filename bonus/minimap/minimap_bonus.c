/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:15 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:29:09 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_draw_player(t_cub *cub)
{
	t_vector	pos_p;
	int			x;
	int			y;

	pos_p.x = MINIMAP_WIDTH / 2;
	pos_p.y = MINIMAP_HEIGHT / 2;
	y = pos_p.y - RADIUS;
	while (y < pos_p.y + RADIUS)
	{
		x = pos_p.x - RADIUS;
		while (x < pos_p.x + RADIUS)
		{
			if (pow(x - pos_p.x, 2) + pow(y - pos_p.y, 2) < pow(RADIUS, 2))
				mlx_put_pixel(cub->mlx.player_rays, x, y, \
				ft_color(255, 0, 0, 255));
			x++;
		}
		y++;
	}
}

static void	ft_draw_rays(t_cub *cub)
{
	int			i;
	t_vector	end;
	t_vector	start;
	float		ray_distance;

	start.x = MINIMAP_WIDTH / 2;
	start.y = MINIMAP_HEIGHT / 2;
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ray_distance = ft_scale_f(cub->rays[i].distance);
		end.x = MINIMAP_WIDTH / 2 + (ray_distance - 1) * \
		cos(cub->rays[i].angle);
		end.y = MINIMAP_HEIGHT / 2 - (ray_distance - 1) * \
		sin(cub->rays[i].angle);
		ft_draw_line(start, end, cub);
		i++;
	}
}

static void	ft_draw_map(t_cub *cub)
{
	t_vector	new;
	t_vector	old;
	t_vector	pos_p;

	pos_p.x = MINIMAP_WIDTH / 2;
	pos_p.y = MINIMAP_HEIGHT / 2;
	old.y = ft_scale_f(cub->player.py) - MINIMAP_HEIGHT / 2;
	new.y = -1;
	while (++new.y < MINIMAP_HEIGHT)
	{
		new.x = -1;
		old.x = ft_scale_f(cub->player.px) - MINIMAP_WIDTH / 2;
		while (++new.x < MINIMAP_WIDTH)
		{
			ft_draw_pixel(cub, old, new, pos_p);
			old.x++;
		}
		old.y++;
	}
}

static void	ft_reset_player_rays(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (++y < MINIMAP_HEIGHT)
	{
		x = -1;
		while (++x < MINIMAP_WIDTH)
			mlx_put_pixel(cub->mlx.player_rays, x, y, ft_color(0, 0, 0, 0));
	}
}

void	ft_render_minimap(t_cub *cub)
{
	ft_reset_player_rays(cub);
	ft_draw_map(cub);
	ft_draw_rays(cub);
	ft_draw_player(cub);
}
