#include "util.h"

void	*ft_calloc(size_t a, size_t b)
{
	size_t	i;
	void	*p;

	i = 0;
	if (!(p = malloc(a * b)))
		return (NULL);
	while (i < (a * b))
	{
		((unsigned char *)p)[i] = '\0';
		i++;
	}
	return (p);
}