/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:46:32 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/02 15:29:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_atoi_plus(char *str, int *i)
{
	int	number;

	if (str[*i] >= '0' && str[*i] <= '9')
		number = 0;
	else
		number = -1;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		number = (number * 10) + (str[*i] - '0');
		if (number > 255)
			return (-1);
		(*i)++;
	}
	return (number);
}

int	*ft_get_color(char *line, t_cub *cub)
{
	int	*color;
	int	i;
	int	j;

	i = 0;
	color = allocate_memory_safely(sizeof(int) * 3, cub);
	if (!color)
		return (NULL);
	j = -1;
	while (++j < 3)
	{
		ft_skip_space(line, &i);
		color[j] = ft_atoi_plus(line, &i);
		if (color[j] == -1)
			return (free(color), NULL);
		if (j == 2)
			break ;
		ft_skip_space(line, &i);
		if (line[i++] != ',')
			return (free(color), NULL);
	}
	ft_skip_space(line, &i);
	if (line[i] && line[i] != '\n')
		return (free(color), NULL);
	return (color);
}

int	ft_set_color(t_cub *cub, int **color, char *line, int *i)
{
	int	j;

	(*i)++;
	j = *i;
	ft_skip_space(line, i);
	if (j == (*i))
		return (FAILED);
	*color = ft_get_color(line + (*i), cub);
	if (!(*color))
		return (FAILED);
	return (SUCCESS);
}
