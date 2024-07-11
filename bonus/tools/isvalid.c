/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:52:42 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 06:24:57 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_valid_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 4 || ft_strcmp(name + (len - 4), ".cub"))
	{
		ft_putstr_fd("Error: Invalid file Name", 2, 1, RED);
		exit(FAILED);
	}
}
