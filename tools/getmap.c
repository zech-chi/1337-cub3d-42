/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:02:04 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 09:47:00 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_skip_space(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int ft_count_vir
int	ft_get_color(char *line)
{
	int	
	return (SUCCESS);
}

int	ft_scan_line(t_cub *cub, char *line)
{
	int	i;
	int	j;

	i = ft_skip_space(line);
	if (!ft_strncmp(line + i, "NO", 2) && !cub->no)
	{
		j = ft_skip_space(line + i + 2);
		cub->no = ft_substr(line, (i + 2 + j), ft_strlen(line) - (i + 2 + j));
	}
	else if (!ft_strncmp(line + i, "SO", 2) && !cub->so)
	{
		j = ft_skip_space(line + i + 2);
		cub->so = ft_substr(line, (i + 2 + j), ft_strlen(line) - (i + 2 + j));
	}
	else if (!ft_strncmp(line + i, "WE", 2) && !cub->we)
	{
		j = ft_skip_space(line + i + 2);
		cub->we = ft_substr(line, (i + 2 + j), ft_strlen(line) - (i + 2 + j));
	}
	else if (!ft_strncmp(line + i, "EA", 2) && !cub->ea)
	{
		j = ft_skip_space(line + i + 2);
		cub->ea = ft_substr(line, (i + 2 + j), ft_strlen(line) - (i + 2 + j));
	}
	else if (!ft_strncmp(line + i, "F", 2) && !cub->cf)
	{
		// later
	}
	else if (!ft_strncmp(line + i, "C", 2) && !cub->cc)
	{
		// later
	}
	else
		return (FAILED);
	return (SUCCESS);
}

void	ft_scan_map(t_cub *cub, char *path)
{
	int 	fd;
	char	*line;
	char	**data;

	fd = ft_open_file(path);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_scan_line(cub))
		{
			ft_putstr_fd("Error: Invalid map", 2, 1, RED);
			free(line);
			exit(FAILED);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
