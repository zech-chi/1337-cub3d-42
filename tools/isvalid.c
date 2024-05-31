#include "../include/cub3d.h"

int	ft_isvalidname(char *name)
{
	int len;

	len = ft_strlen(name);
	if (len < 4)
		return (ft_putstr_fd("Error: Invalid file Name", 2, 1, RED), FAILED);
	if (ft_strcmp(name + (len - 4), ".cub"))
		return ( ft_putstr_fd("Error: Invalid file Name", 2, 1, RED), FAILED);
	return (SUCCESS);
}