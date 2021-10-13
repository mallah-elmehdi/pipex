#include "util.h"

int			delim_length(char const *str, char delim)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == delim)
			length++;
		i++;
	}
	return (length);
}

char		**free_splited_str(char **splited_str, int i)
{
	while (i >= 0)
		free(splited_str[i--]);
	free(splited_str);
	return (NULL);
}

char		**ft_split(const char *str, char delim)
{
	char    **splited_str;
	int	    i;
	int		j;
	int		k;

	j = 0;
	if (str == NULL)
		return (NULL);
	splited_str = (char **)ft_calloc(sizeof(char*), delim_length(str, delim) + 2);
	if (splited_str == NULL)
		return (NULL);
	while (i < delim_length(str, delim) + 1)
	{
		splited_str[i] = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1); 
		if (splited_str[i] == NULL)
			return (free_splited_str(splited_str, i - 1));
		k = 0;
		while (str[j])
		{
			if (str[j] == delim)
			{
				j++;
				break ;
			}
			splited_str[i][k++] = str[j++];
		}
		i++;
	}
	return (splited_str);
}