/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_line_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:09:08 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 22:33:09 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_check_internal_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '\n' && line[i] != ' ' && line[i] != 'D'
			&& line[i] != 'T')
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

int	ft_is_full_spaces(char *line)
{
	while (*line == ' ')
		line++;
	return (*line == '\0');
}

int	ft_is_full_spaces_newline(char *line)
{
	while (*line == ' ' || *line == '\n')
		line++;
	return (*line == '\0');
}

int	ft_check_content_line(char *line, int *check)
{
	if ((*line == '\n' || ft_is_full_spaces_newline(line)) && (*check))
		return (FAILED);
	if (ft_check_internal_char(line))
		return (FAILED);
	return (SUCCESS);
}

int	ft_set_coordonates_textures(char **texture, char *line, int *i)
{
	int	j;

	(*i) += 2;
	j = *i;
	ft_skip_space(line, i);
	if (j == (*i))
		return (FAILED);
	*texture = ft_substr(line, *i, ft_strlen(line) - (*i) - 1);
	if (!(*texture))
		return (FAILED);
	return (SUCCESS);
}
