/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:52 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/12 09:28:49 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

float	ft_periodic(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	ft_between(float alpha, float angle_start, float angle_end)
{
	if (angle_start <= alpha && alpha <= angle_end)
		return (1);
	return (0);
}

float	ft_min(float a, float b)
{
	if (a > b)
		return (b);
	return (a);
}

float	ft_get_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)));
}

float	ft_scale_f(float prev)
{
	float	new;

	new = (prev * PIXEL_MINI) / PIXEL;
	return (new);
}
