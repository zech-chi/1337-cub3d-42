/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:50:38 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 02:04:17 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_min_d(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max_d(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

uint32_t	ft_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
