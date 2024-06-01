/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:53:43 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 15:41:45 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/cub3d.h>

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

static int	ft_good_neighbours(t_cub *cub, int r, int c)
{
	if (r == 0 || r == cub->rows - 1 || c = 0 || c == cub->cols - 1)
		return (0);
	if (!ft_search(cub->map[r - 1][c], "01NSEW"))
		return (0);
	if (!ft_search(cub->map[r - 1][c + 1], "01NSEW"))
		return (0);
	if (!ft_search(cub->map[r][c + 1], "01NSEW"))
		return (0);
	if (!ft_search(cub->map[r + 1][c + 1], "01NSEW"))
		return (0);
	if (!ft_search(cub->map[r + 1][c], "01NSEW"))
		return (0);
	if (!ft_search(cub->map[r + 1][c - 1], "01NSEW"))
		return (0);
	if (!ft_search(cub->map[r][c - 1], "01NSEW"))
		return (0);
	if (!ft_search(cub->map[r - 1][c - 1], "01NSEW"))
		return (0);
}

int	ft_is_valid_map(t_cub *cub)
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
				if (count > 1 || !ft_good_neighbours(cub, r, c))
					return (0);
			}
		}
	}
	return (1);
}
