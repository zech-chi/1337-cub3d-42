/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:50:38 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:28:54 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
