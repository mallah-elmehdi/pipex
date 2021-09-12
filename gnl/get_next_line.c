/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 07:20:55 by emallah           #+#    #+#             */
/*   Updated: 2019/11/20 20:57:43 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				a;
	int				j;
	static char		*one_for_all;

	j = 0;
	if (line == NULL)
		return (-1);
	if (100 < 0)
		return (-1);
	if (!(*line = (char*)ft_calloc(sizeof(char), 100 + 1)))
		return (-1);
	if ((a = (check_out(&one_for_all, line, &j)) > 0))
		return (1);
	if (a < 0)
		return (-1);
	if (one_for_all)
		free_it(&one_for_all);
	if (!(one_for_all = (char*)ft_calloc(sizeof(char), 100 + 1)))
		return (-1);
	if ((a = fill_it(&one_for_all, line, &j, &fd)) > 0)
		return (1);
	if (a < 0)
		return (-1);
	free_it(&one_for_all);
	return (0);
}

void	*ft_calloc(size_t type, size_t size)
{
	size_t	i;
	void	*the_str;

	i = 0;
	if (!(the_str = malloc(type * size)))
		return (NULL);
	((unsigned char*)the_str)[(type * size) - 1] = '\0';
	((unsigned char*)the_str)[0] = '\0';
	return (the_str);
}

void	free_it(char **s)
{
	free(*s);
	*s = NULL;
}
