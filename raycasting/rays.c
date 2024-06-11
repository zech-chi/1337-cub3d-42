/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:23:48 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/10 20:34:33 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	ft_raycasting(t_cub *cub, double ray_angle, int	i)
{
	double	hit_x;
	double	hit_y;
	int		

	ray_angle = ft_periodic(ray_angle);
	cub->rays[i].angle = ray_angle;
	cub->rays[i].down = ray_angle > 0 && ray_angle < M_PI;
	cub->rays[i].up = !cub->rays[i].down;
	cub->rays[i].right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	cub->rays[i].left = !cub->rays[i].right;

}

void	ft_rays(t_cub *cub)
{
	double	ray_angle;
	int		i;

	ray_angle = cub->player.angle - M_PI / 6.0;
	i = 0;
	while (i < NUMBER_RAYS)
	{
		ft_raycasting(cub, ray_angle, i);
		ray_angle += (M_PI / (3.0 * NUMBER_RAYS));
	}
}
