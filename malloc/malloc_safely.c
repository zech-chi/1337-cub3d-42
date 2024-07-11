/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_safely.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:58:30 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/11 04:43:35 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*allocate_memory_safely(size_t bytes, t_cub *cub)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		ft_putstr_fd("Error: failed to allocate memory", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	return (ptr);
}
