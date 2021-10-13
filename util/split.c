/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:13:04 by emallah           #+#    #+#             */
/*   Updated: 2021/10/13 11:13:06 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	delim_length(char const *str, char delim)
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

char	**free_splited(char **splited, int i)
{
	while (i >= 0)
		free(splited[i--]);
	free(splited);
	return (NULL);
}

int	get_part(const char *str, char delim, int part)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (part == 0)
			return (i);
		if (str[i] == delim)
			part--;
		i++;
	}
	return (i);
}

char	*fill_str(const char *str, char delim, int part)
{
	char	*temp;
	int		j;
	int		k;

	k = 0;
	j = get_part(str, delim, part);
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (temp == NULL)
		return (NULL);
	while (str[j])
	{
		if (str[j] == delim)
		{
			j++;
			break ;
		}
		temp[k++] = str[j++];
	}
	return (temp);
}

char	**ft_split(const char *str, char delim)
{
	char	**splited;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	splited = (char **)ft_calloc(sizeof (char *), delim_length(str, delim) + 2);
	if (splited == NULL)
		return (NULL);
	while (i < delim_length(str, delim) + 1)
	{
		splited[i] = fill_str(str, delim, i);
		if (splited[i] == NULL)
			return (free_splited(splited, i - 1));
		i++;
	}
	return (splited);
}
