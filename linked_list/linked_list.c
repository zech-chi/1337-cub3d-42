/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:30:08 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 19:30:05 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;
	char	*line;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	line = content;
	if (line[ft_strlen(line) - 1] == '\n')
		line [ft_strlen(line) - 1] = '\0';
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (*lst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}
