#include <stdio.h>
#include <stdlib.h>

void	ft_skip_space(char *str, int *i)
{
	if (!str)
		return ;
	while (str[*i] == ' ')
		(*i)++;
}

int ft_atoi_plus(char *str, int *i)
{
    int number;

    if (str[*i] >= '0' && str[*i] <= '9')
        number = 0;
    else
        number = -1;
    while(str[*i] && str[*i] >= '0' && str[*i] <= '9')
    {
        number = (number * 10) + (str[*i] - '0');
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
    int j;

    i = 0;
    color = malloc(sizeof(int) * 3);
    if (!color)
        return (NULL);
    j = -1;
    while (++j < 3)
    {
        ft_skip_space(line, &i);
        color[j] = ft_atoi_plus(line, &i);
        if (color[j] == -1)
            return (free(color), NULL);
        if (j == 2)
            break ;
        ft_skip_space(line, &i);
        if (line[i++] != ',')
            return (free(color), NULL);
    }
    ft_skip_space(line, &i);
    if (line[i])
        return (free(color), NULL);
    return (color);
}


void ft_up(char **s)
{
    *s = "fr";
}

int  main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int *l = ft_get_color(av[1]);
    if (!l)
        return (printf("error\n"), 1);
    for (int i = 0; i < 3; i++)
        printf("%d\n", l[i]);

    char *s = "33d";
    ft_up(&s);
    printf("%s\n", s);
    return (0);
}