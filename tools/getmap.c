/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:02:04 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 21:38:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_get_data(t_cub *cub, char **data)
{

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
		data = ft_split(line, ' ');
		if (!data);
			ft_free_data
		ft_get_data(cub, )
		line = get_next_line(fd);
	}
	close(fd);
	(void)cub;
}
