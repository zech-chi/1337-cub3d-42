/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:26:45 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/02 14:50:41 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_search(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_neighbours(t_cub *cub, int r, int c)
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

int	ft_scan_map(t_cub *cub)
{
	int	r;
	int	c;
	int	count;

	count = 0;
	r = -1;
	while (++r < cub->rows)
	{
		c = -1;
		while (++c < cub->cols)
		{
			if (ft_search(cub->map[r][c], "NSEW"))
				count++;
			if (ft_search(cub->map[r][c], "0NSEW"))
			{
				if (count > 1 || ft_check_neighbours(cub, r, c))
					return (FAILED);
			}
		}
	}
	if (count == 0)
		return (FAILED);
	return (SUCCESS);
}
