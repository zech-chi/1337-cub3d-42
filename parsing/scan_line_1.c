/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_line_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:04:07 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/02 15:31:55 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_scan_line_part1(t_cub *cub, char *line)
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
		return (ft_set_color(cub, &(cub->cf), line, &i));
	else if (!ft_strncmp(line + i, "C", 1) && !cub->cc)
		return (ft_set_color(cub, &(cub->cc), line, &i));
	return (FAILED);
}

static int	ft_scan_line_part2(t_cub *cub, char *line, int *check)
{
	t_list	*new_node;

	if (ft_check_content_line(line, check))
		return (FAILED);
	if (ft_is_full_spaces_newline(line) && !(*check))
		return (SUCCESS);
	(*check) = 1;
	new_node = ft_lstnew(line);
	if (!new_node)
		return (FAILED);
	ft_lstadd_back(&(cub->head), new_node);
	return (SUCCESS);
}

void	ft_scan_line(t_cub *cub, int *check)
{
	if (ft_part1_full(cub))
	{
		if (ft_scan_line_part2(cub, cub->line, check))
		{
			ft_putstr_fd("Error: Invalid map", 2, 1, RED);
			ft_free_data(cub);
			exit(FAILED);
		}
	}
	else
	{
		if (ft_scan_line_part1(cub, cub->line))
		{
			ft_putstr_fd("Error: Invalid map", 2, 1, RED);
			ft_free_data(cub);
			exit(FAILED);
		}
	}
}
