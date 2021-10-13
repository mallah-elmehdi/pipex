/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:12:08 by emallah           #+#    #+#             */
/*   Updated: 2021/10/13 11:12:15 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **av, char **env, int *fd)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		sys_error(NULL);
	if (pid == 0)
		cmd_1_exec(av, env, fd);
	waitpid(pid, &status, 0);
	close(fd[1]);
	pid = fork();
	if (pid == -1)
		sys_error(NULL);
	if (pid == 0)
		cmd_2_exec(av, env, fd);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
	close(fd[0]);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];

	if (ac != 5)
		prg_error("pipex: wrong number of arguments!\n", NULL);
	if (pipe(fd) == -1)
		sys_error(NULL);
	pipex(av, env, fd);
	return (EXIT_SUCCESS);
}
