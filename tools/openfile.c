#include "../include/cub3d.h"

int	ft_openfile(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to open file: ", 2, 0, RED);
		ft_putstr_fd(path, 2, 1, WHITE);
		exit(FAILED);
	}
	return (fd);
}