/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:52 by zelabbas          #+#    #+#             */
/*   Updated: 2024/06/10 18:57:39 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_between(double alpha, double angle_start, double angle_end)
{
	if (angle_start <= alpha && alpha <= angle_end)
		return (1);
	return (0);
}
