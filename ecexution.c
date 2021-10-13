/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecexution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:12:02 by emallah           #+#    #+#             */
/*   Updated: 2021/10/13 11:12:04 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_2_exec(char **av, char **env, int *fd)
{
	int		fdout;
	char	**cmd_w_opt;
	char	*cmd2;

	fdout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fdout == -1)
		sys_error(av[4]);
	cmd_w_opt = ft_split(av[3], ' ');
	if (cmd_w_opt == NULL)
		sys_error(NULL);
	if (cmd_w_opt[0][0] == '/')
		cmd2 = ft_strdup(cmd_w_opt[0]);
	else
		cmd2 = get_cmd_path(cmd_w_opt[0], env);
	if (cmd2 == NULL)
		prg_error("pipex: command not found: ", cmd_w_opt);
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	if (execve(cmd2, cmd_w_opt, env) == -1)
		sys_error(av[3]);
}

void	cmd_1_exec(char **av, char **env, int *fd)
{
	int		fdin;
	char	**cmd_w_opt;
	char	*cmd1;

	fdin = open(av[1], O_RDONLY, 0777);
	if (fdin == -1)
		sys_error(av[1]);
	cmd_w_opt = ft_split(av[2], ' ');
	if (cmd_w_opt == NULL)
		sys_error(NULL);
	if (cmd_w_opt[0][0] == '/')
		cmd1 = ft_strdup(cmd_w_opt[0]);
	else
		cmd1 = get_cmd_path(cmd_w_opt[0], env);
	if (cmd1 == NULL)
		prg_error("pipex: command not found: ", cmd_w_opt);
	dup2(fdin, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(cmd1, cmd_w_opt, env))
		sys_error(av[2]);
}
