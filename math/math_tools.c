/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:52 by zelabbas          #+#    #+#             */
/*   Updated: 2024/06/10 20:07:49 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	ft_periodic(double angle)
{
	double	new_angle;

	new_angle = angle;
	if (angle < 0)
		new_angle += 2 * M_PI;
	else if (angle >= 2 * M_PI)
		new_angle -= 2 * M_PI;
	return (new_angle);
}

int	ft_between(double alpha, double angle_start, double angle_end)
{
	if (angle_start <= alpha && alpha <= angle_end)
		return (1);
	return (0);
}
