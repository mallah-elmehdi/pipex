#include "util.h"

void	free_double(char **double_ptr)
{
	int	i;

	i = 0;
	while (double_ptr[i])
	{
        free(double_ptr[i]);
        i++;
	}
    free(double_ptr);
}