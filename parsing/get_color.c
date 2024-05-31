/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:46:32 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 23:00:51 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_skip_space(char *str, int *i)
{
	if (!str)
		return (-1);
	while (str[*i] == ' ')
		(*i)++;
}

int ft_atoi_plus(char *str, int *i)
{
    int number;

    number = 0;
    while(str[*i] && str[*i] >= '0' && str[*i] <= '9')
    {
        number *= 10 + (str[*i] - '0');
        if (number > 255)
            return (-1);
        (*i)++;
    }
    return (number);
}

int *ft_get_color(char *line)
{
    int *color;
    int i;

    i = 0;
    color = allocate_memory_safely(sizeof(int) * 3);
    if (!color)
        return (NULL);
    ft_skip_space(line, &i)
    color[0] = ft_atoi_plus(line, &i);

}
