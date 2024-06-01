/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:34:47 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 13:05:58 by zech-chi         ###   ########.fr       */
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

	if (*line == '\n' || ft_is_full_spaces(line))
		return (SUCCESS);
	i = 0;
	ft_skip_space(line, &i);
	if (!ft_strncmp(line + i, "NO", 2) && !cub->no)
		return (ft_set_coordonates_textures(&cub->no, line, &i));
	else if (!ft_strncmp(line + i, "SO", 2) && !cub->so)
		return (ft_set_coordonates_textures(&cub->so, line, &i));
	else if (!ft_strncmp(line + i, "WE", 2) && !cub->we)
		return (ft_set_coordonates_textures(&cub->we, line, &i));
	else if (!ft_strncmp(line + i, "EA", 2) && !cub->ea)
		return (ft_set_coordonates_textures(&cub->ea, line, &i));
	else if (!ft_strncmp(line + i, "F", 1) && !cub->cf)
	{
		return (ft_set_color(cub, &(cub->cf), line, &i));
	}
	else if (!ft_strncmp(line + i, "C", 1) && !cub->cc)
		return (ft_set_color(cub, &(cub->cc), line, &i));

	return (FAILED);
}

void	ft_scan_map(t_cub *cub, char *path)
{
	int		fd;
	char	*line;

	fd = ft_open_file(path);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_part1_full(cub))
		{
			if (ft_scan_line_part2(cub, line)) // todo
			{
				ft_putstr_fd("Error: Invalid map", 2, 1, RED);
				free(line);
				ft_free_data(cub);
				close(fd);
				exit(FAILED);
			}
		}
		else
		{
			if (ft_scan_line_part1(cub, line))
			{
				ft_putstr_fd("Error: Invalid map", 2, 1, RED);
				free(line);
				ft_free_data(cub);
				close(fd);
				exit(FAILED);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
