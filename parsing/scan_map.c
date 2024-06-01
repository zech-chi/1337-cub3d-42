/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:34:47 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 16:48:16 by zelabbas         ###   ########.fr       */
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
/*part 2*/
int	ft_check_internal_char(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '\n' && line[i] != ' ')
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

int	ft_check_content_line(char* line, int *check)
{
	if ((*line == '\n' || ft_is_full_spaces(line)) && (*check))
		return (FAILED);
	if (ft_check_internal_char(line))
		return (FAILED);
	return (SUCCESS);
}

int	ft_scan_line_part2(t_cub *cub, char *line, int *check)
{
	t_list* new_node;

	if (line[ft_strlen(line) - 1] == '\n')
		line [ft_strlen(line) - 1] = '\0';
	if (*line == '\0')
		return (SUCCESS);
	if (ft_check_content_line(line, check))
		return (FAILED);
	(*check) = 1;
	new_node = ft_lstnew(line);
	if (!new_node)
		return (FAILED);
	ft_lstadd_back(&(cub->head), new_node);
	return (SUCCESS);
}

void	ft_set_rows_cols(t_cub *cub)
{
	size_t 	max_len;
	t_list	*tmp;

	tmp = cub->head;
	cub->rows = ft_lstsize(tmp);
	max_len = 0;
	while (tmp)
	{
		printf("%s->%zu\n", tmp->content, ft_strlen(tmp->content));
		if (max_len < ft_strlen(tmp->content))
			max_len = ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	cub->cols = max_len;
}
/*part 2*/

void	ft_scan_map(t_cub *cub, char *path)
{
	int	check;

	cub->fd = ft_open_file(path);
	cub->line = get_next_line(cub->fd);
	check = 0;
	while (cub->line)
	{
		if (ft_part1_full(cub))
		{
			if (ft_scan_line_part2(cub, cub->line, &check)) // todo
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
		free(cub->line);
		cub->line = get_next_line(cub->fd);
	}
	close(cub->fd);
	ft_set_rows_cols(cub);
}
