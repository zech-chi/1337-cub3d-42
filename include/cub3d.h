/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:52 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 12:25:54 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 1
# define SUCCESS 0
# define FAILED 1

/* cub3d struct */
typedef struct s_cub {
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*cf;
	int		*cc;
	int		rows;
	int		cols;
	int		pr;
	int		pc;
}	t_cub;

/* get_next_line/get_next_line_utils.c */
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	shift_buff_or_clean_it(char *buff, size_t j);
int		has_the_end(char *buff, char **line);

/* get_next_line/get_next_line.c */
char	*get_next_line(int fd);

/* tools/split.c */
char	**ft_split(char const *s, char c);


#endif