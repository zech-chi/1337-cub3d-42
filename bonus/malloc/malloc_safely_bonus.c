/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_safely_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:58:30 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/15 18:56:06 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	*allocate_memory_safely(size_t bytes, t_cub *cub)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		ft_putstr_fd("Error\nFailed to allocate memory", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	return (ptr);
}
