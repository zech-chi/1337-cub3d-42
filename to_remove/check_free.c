/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:42:49 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 14:45:31 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

void	f()
{
	system("leaks a.out");
}

int main()
{
	char *ptr;

	atexit(f);
	ptr = ft_strdup("hello world");
	ptr[3] = 0;
	printf("%s\n", ptr);
	free(ptr);

}