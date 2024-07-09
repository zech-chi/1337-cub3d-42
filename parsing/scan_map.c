/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:26:45 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 22:33:26 by zech-chi         ###   ########.fr       */
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

void	ft_check_neighbours_door(t_cub *cub)
{
	int r;
	int	c;

	r = -1;
	while ( ++r< cub->rows)
	{
		c = -1;
		while (++c < cub->cols)
		{
			if (cub->map[r][c] == 'D')
			{
				if (cub->map[r - 1][c] == '1' && cub->map[r + 1][c] == '1')
				{
					if ((cub->map[r][c - 1] == '1' || cub->map[r][c + 1] == '1')
						|| ((cub->map[r][c - 1] == 'D' || cub->map[r][c + 1] == 'D')))
					{
						ft_putstr_fd("Error: invalid door position!", 2, 1, RED);
						exit(FAILED);
					}
				}
				else if (cub->map[r][c - 1] == '1' && cub->map[r][c + 1] == '1')
				{
					if ((cub->map[r - 1][c] == '1' || cub->map[r + 1][c] == '1')
						|| cub->map[r - 1][c] == 'D' || cub->map[r + 1][c] == 'D')
					{
						ft_putstr_fd("Error: invalid door position!", 2, 1, RED);

						exit(FAILED);
					}
				}
				else
				{
					ft_putstr_fd("Error: invalid door position!", 2, 1, RED);
					exit(FAILED);
				}
			}
		}
	}
	
}

void	ft_scan_map(t_cub *cub)
{
	int	r;
	int	c;

	r = -1;
	while (++r < cub->rows)
	{
		c = -1;
		while (++c < cub->cols)
		{
			if (ft_search(cub->map[r][c], "NSEW"))
			{
				if (cub->player.pr != -1 || cub->player.pc != -1)
					exit(FAILED);
				cub->player.pr = r;
				cub->player.pc = c;
				cub->player.sens = cub->map[r][c];
			}
			if (ft_search(cub->map[r][c], "0NSEWDT") && ft_check_neighbours(cub, r, c))
				exit(FAILED);
		}
	}
	ft_check_neighbours_door(cub);
}
