/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:12:38 by emallah           #+#    #+#             */
/*   Updated: 2021/10/13 11:12:39 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	sys_error(const char *extra_msg)
{
	char	*msg;

	msg = strerror(errno);
	write(2, "pipex: ", ft_strlen("pipex: "));
	write(2, msg, ft_strlen(msg));
	if (extra_msg)
	{
		write(2, ": ", 2);
		write(2, extra_msg, ft_strlen(extra_msg));
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	prg_error(const char *err, char **cmd_w_opt)
{
	write(2, err, ft_strlen(err));
	if (cmd_w_opt)
	{
		write(2, cmd_w_opt[0], ft_strlen(cmd_w_opt[0]));
		write(2, "\n", 1);
		free_double(cmd_w_opt);
		if (ft_strnstr(err, "pipex: command", ft_strlen("pipex: command")))
			exit(127);
	}
	exit(EXIT_FAILURE);
}
