/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:19:56 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 06:33:34 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*s_dup;
	size_t	i;

	if (!str)
		return (NULL);
	s_dup = malloc(ft_strlen(str) + 1);
	if (!s_dup)
		return (NULL);
	i = -1;
	while (str[++i])
		s_dup[i] = str[i];
	s_dup[i] = '\0';
	return (s_dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if ((!s1 && !s2))
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	new_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_s)
		return (free(s1), free(s2), NULL);
	i = -1;
	while (s1[++i])
		new_s[i] = s1[i];
	j = 0;
	while (s2[j])
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	return (free(s1), free(s2), new_s);
}

void	shift_buff_or_clean_it(char *buff, size_t right)
{
	size_t	left;

	left = 0;
	while (right < BUFFER_SIZE)
		buff[left++] = buff[right++];
	while (left < BUFFER_SIZE && buff[left])
		buff[left++] = '\0';
}

int	has_the_end(char *buff, char **line)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (i < BUFFER_SIZE && buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (i == BUFFER_SIZE || buff[i] == '\0')
	{
		*line = ft_strjoin(*line, ft_strdup(buff));
		shift_buff_or_clean_it(buff, BUFFER_SIZE);
		return (0);
	}
	temp = malloc(i + 2);
	if (!temp)
		return (-1);
	j = -1;
	while (++j < i)
		temp[j] = buff[j];
	temp[j++] = '\n';
	temp[j] = '\0';
	*line = ft_strjoin(*line, temp);
	shift_buff_or_clean_it(buff, i + 1);
	return (1);
}
