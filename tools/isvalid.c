#include "../include/cub3d.h"

int	ft_isvalidname(char *name)
{
	int len;

	len = ft_strlen(name);
	if (len < 4)
		return (FAILED);
	if (ft_strcmp(name + (len - 4), ".cub"))
		return (FAILED);
	return (SUCCESS);
}