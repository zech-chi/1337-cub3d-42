/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:52:42 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:31:41 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
