#include "util.h"

int ft_strlen(const char *str)
{
	int i;
	
	i = 0;
	while (str && str[i])
		i++;	
	return (i);
}