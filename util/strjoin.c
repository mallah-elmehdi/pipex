#include "util.h"

size_t	lenth(const char *s, const char *s0)
{
	if (s == NULL && s0 != NULL)
		return (ft_strlen(s0) + 1);
	else if (s != NULL && s0 == NULL)
		return (ft_strlen(s) + 1);
	else
		return (ft_strlen(s) + ft_strlen(s0) + 1);
}

char	*ft_strjoin(const char *s, const char *s0)
{
	char	*p;
	size_t	j;

	if (s == NULL && s0 == NULL)
		return (NULL);
	j = lenth(s, s0);
	if (!(p = (char*)ft_calloc(sizeof(char), j)))
		return (NULL);
	while (s != NULL && *s != '\0')
		*p++ = *(char*)s++;
	while (s0 != NULL && *s0 != '\0')
		*p++ = *(char*)s0++;
	return (&p[-j + 1]);
}