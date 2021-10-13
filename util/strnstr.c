/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:13:26 by emallah           #+#    #+#             */
/*   Updated: 2021/10/13 11:13:27 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (str1[i] && i < n)
	{
		a = 0;
		while (str1[i + a] == str2[a] && (i + a) < n)
		{
			a++;
			if (str2[a] == '\0')
				return (&((char *)str1)[i]);
		}
		i++;
	}
	return (NULL);
}
