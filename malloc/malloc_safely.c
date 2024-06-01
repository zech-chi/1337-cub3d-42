#include "../include/cub3d.h"

void	*allocate_memory_safely(size_t bytes, t_cub *cub)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		ft_putstr_fd("Error: failed to allocate memory", 2, 1,RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	return (ptr);
}
