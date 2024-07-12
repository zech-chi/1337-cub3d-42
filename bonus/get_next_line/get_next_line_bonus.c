/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:36:27 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:28:01 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			r;
	int			e;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	line = NULL;
	if (has_the_end(buff, &line))
		return (line);
	r = read(fd, buff, BUFFER_SIZE);
	e = has_the_end(buff, &line);
	while (r > 0 && e == 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		e = has_the_end(buff, &line);
	}
	if (r == -1 || e == -1 || (line && ft_strlen(line) == 0))
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
