/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:19:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:32:05 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static char	*help(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = 0;
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (help());
	size = ft_strlen(s) - start;
	if (len < size)
		size = len;
	ptr = malloc((size + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
