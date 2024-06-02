/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:34:47 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/02 09:56:18 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_set_coordonates_textures(char **texture, char *line, int *i)
{
	(*i) += 2;
	ft_skip_space(line, i);
	*texture = ft_substr(line, *i, ft_strlen(line) - (*i) - 1);
	if (!(*texture))
		return (FAILED);
	return (SUCCESS);
}

int	ft_part1_full(t_cub *cub)
{
	if (cub->ea)
	{
		if (*(cub->ea) == '\0')
			return (0);
	}
	if (cub->we)
	{
		if (*(cub->we) == '\0')
			return (0);
	}
	if (cub->so)
	{
		if (*(cub->so) == '\0')
			return (0);
	}
	if (cub->no)
	{
		if (*(cub->no) == '\0')
			return (0);
	}
	return (cub->we && cub->ea && cub->so && cub->no && cub->cf && cub->cc);
}


int	ft_is_full_spaces(char *line)
{
	while (*line == ' ')
		line++;
	return (*line == '\0');
}


int	ft_scan_line_part1(t_cub *cub, char *line)
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
int	ft_is_full_spaces_newline(char *line)
{
	while (*line == ' ' || *line == '\n')
		line++;
	return (*line == '\0');
}

static int	ft_check_neighbours(t_cub *cub, int r, int c)
{
	if ((*line == '\n' || ft_is_full_spaces_newline(line)) && (*check))
		return (FAILED);
	if (cub->map[r - 1][c] == ' ')
		return (FAILED);
	return (SUCCESS);
}
int	ft_scan_line_part2(t_cub *cub, char *line, int *check)
{
	t_list* new_node;

	if (ft_check_content_line(line, check))
		return (FAILED);
	if (ft_is_full_spaces_newline(line) && !(*check))
		return (SUCCESS);
	(*check) = 1;
	new_node = ft_lstnew(line);
	if (!new_node)
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
			if (ft_scan_line_part2(cub, cub->line, &check))
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
