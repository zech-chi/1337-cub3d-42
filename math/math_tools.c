/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:52 by zelabbas          #+#    #+#             */
/*   Updated: 2024/06/28 21:41:29 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	ft_periodic(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle >= (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	ft_between(double alpha, double angle_start, double angle_end)
{
	if (angle_start <= alpha && alpha <= angle_end)
		return (1);
	return (0);
}

double	ft_min(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double	ft_get_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)));
}
