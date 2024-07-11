/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:26:38 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 00:17:05 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	ft_set_rows_cols(t_cub *cub)
{
	size_t	max_len;
	t_list	*tmp;

	tmp = cub->head;
	cub->rows = ft_lstsize(tmp);
	max_len = 0;
	while (tmp)
	{
		if (max_len < ft_strlen(tmp->content))
			max_len = ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	cub->cols = max_len;
}

void	ft_scan_file(t_cub *cub, char *path)
{
	int	check;

	cub->fd = ft_open_file(path);
	cub->line = get_next_line(cub->fd);
	check = 0;
	while (cub->line)
	{
		ft_scan_line(cub, &check);
		free(cub->line);
		cub->line = NULL;
		cub->line = get_next_line(cub->fd);
	}
	close(cub->fd);
	cub->fd = -1;
	ft_set_rows_cols(cub);
}
