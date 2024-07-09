/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headbob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:17:04 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/09 15:24:58 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_head_bobbing(t_cub *cub)
{
	if (cub->player.is_walking)
	{
		cub->player.bobbing_time += cub->player.bobbing_speed;
		cub->player.head_bobbing_offset = sin(cub->player.bobbing_time * \
		cub->player.bobbing_frequency) * cub->player.bobbing_amplitude;
		if (cub->player.head_bobbing_offset < 0)
			cub->player.head_bobbing_offset *= -1;
	}
	else
	{
		cub->player.bobbing_time = 0.0;
		cub->player.head_bobbing_offset = 0.0;
	}
}
