/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:05:53 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 21:29:26 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*ft_spaces(int n)
{
	char	*spaces;
	int		i;

	spaces = malloc(n + 1);
	if (!spaces)
		return (NULL);
	i = 0;
	while (i < n)
		spaces[i++] = ' ';
	spaces[i] = 0;
	return (spaces);
}

void	ft_create_map(t_cub *cub)
{
	t_list	*node;
	int		r;
	char	*a;
	char	*b;

	if (!cub->head)
		return ;
	cub->map = allocate_memory_safely(sizeof(char *) * (cub->rows + 1), cub);
	r = 0;
	node = cub->head;
	while (node)
	{
		a = ft_strdup(node->content);
		b = ft_spaces(cub->cols - ft_strlen(a));
		cub->map[r] = ft_strjoin(a, b);
		if (!a || !b || !cub->map[r])
		{
			ft_free_data(cub);
			// ft_free_list(cub->head);
			exit(FAILED);
		}
		node = node->next;
		r++;
	}
	cub->map[r] = NULL;
}
