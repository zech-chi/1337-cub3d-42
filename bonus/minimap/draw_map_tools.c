/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:23:48 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/09 22:54:20 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_draw_inside(t_cub *cub, t_vector new, t_vector old)
{
	int	r;
	int	c;

	r = old.y / PIXEL_MINI;
	c = old.x / PIXEL_MINI;
	if (cub->map[r][c] == ' ')
		mlx_put_pixel(cub->mlx.minimap, new.x, new.y, ft_color(150, 0, 0, 255));
	else if (cub->map[r][c] == '1')
		mlx_put_pixel(cub->mlx.minimap, new.x, new.y, \
		ft_color(255, 255, 255, 255));
	else if (cub->map[r][c] == '0')
		mlx_put_pixel(cub->mlx.minimap, new.x, new.y, ft_color(0, 0, 0, 255));
	else if (cub->map[r][c] == 'D')
	{
		if (r == cub->player.pr && c == cub->player.pc)
			mlx_put_pixel(cub->mlx.minimap, new.x, new.y, \
			ft_color(0, 0, 0, 255));
		else
			mlx_put_pixel(cub->mlx.minimap, new.x, new.y, \
			ft_color(139, 69, 19, 255));
	}
	else if (cub->map[r][c] == 'T')
		mlx_put_pixel(cub->mlx.minimap, new.x, new.y, ft_color(0, 150, 0, 255));
}

void	ft_draw_pixel(t_cub *cub, t_vector old, t_vector new, t_vector pos_p)
{
	if (old.x >= 0 && old.y >= 0 && old.x < cub->cols * PIXEL_MINI && \
	old.y < cub->rows * PIXEL_MINI && pow(new.x - pos_p.x, 2) + \
	pow(new.y - pos_p.y, 2) < pow(MINIMAP_RADIUS, 2))
	{
		ft_draw_inside(cub, new, old);
	}
	else if (pow(new.x - pos_p.x, 2) + pow(new.y - pos_p.y, 2) \
	< pow(MINIMAP_RADIUS, 2))
		mlx_put_pixel(cub->mlx.minimap, new.x, new.y, ft_color(150, 0, 0, 255));
}
