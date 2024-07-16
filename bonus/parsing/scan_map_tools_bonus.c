/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map_tools_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:19:50 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/15 18:57:19 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_check_door_help(t_cub *cub, int r, int c)
{
	bool	valid;

	valid = true;
	if (cub->map[r - 1][c] == '1' && cub->map[r + 1][c] == '1')
	{
		if ((cub->map[r][c - 1] == '1' || cub->map[r][c + 1] == '1')
			|| ((cub->map[r][c - 1] == 'D' || cub->map[r][c + 1] == 'D')))
			valid = false;
	}
	else if (cub->map[r][c - 1] == '1' && cub->map[r][c + 1] == '1')
	{
		if ((cub->map[r - 1][c] == '1' || cub->map[r + 1][c] == '1')
			|| cub->map[r - 1][c] == 'D' || cub->map[r + 1][c] == 'D')
			valid = false;
	}
	else
		valid = false;
	if (!valid)
	{
		ft_putstr_fd("Error\ninvalid door position!", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
}

void	ft_check_neighbours_door(t_cub *cub)
{
	int	r;
	int	c;

	r = -1;
	while (++r < cub->rows)
	{
		c = -1;
		while (++c < cub->cols)
		{
			if (cub->map[r][c] == 'D')
				ft_check_door_help(cub, r, c);
		}
	}
}

int	ft_check_neighbours(t_cub *cub, int r, int c)
{
	if (r == 0 || r == cub->rows - 1 || c == 0 || c == cub->cols - 1)
		return (FAILED);
	if (cub->map[r - 1][c] == ' ')
		return (FAILED);
	if (cub->map[r][c + 1] == ' ')
		return (FAILED);
	if (cub->map[r + 1][c] == ' ')
		return (FAILED);
	if (cub->map[r][c - 1] == ' ')
		return (FAILED);
	return (SUCCESS);
}
