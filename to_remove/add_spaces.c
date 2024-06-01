/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:19:57 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 14:30:31 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

char *ft_n_space(int n)
{
	char *r;
	int	i;

	r = malloc(n + 1);
	if (!r)
		return NULL;
	i = 0;
	while (i < n)
		r[i++] = '$';
	r[i] = 0;
	return (r);
}

int	main(int ac, char **av)
{
	char *res;

	if (ac != 2)
		return (1);
	res = ft_strjoin(ft_strdup(av[1]), ft_n_space(10 - ft_strlen(av[1])));
	printf("%s\n", res);
	return (0);
}