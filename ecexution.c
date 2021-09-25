#include "pipex.h"

void cmd_2_exec(char **av, char **env, int *fd)
{
	int fdout;
	char **cmd_w_opt;
	char *cmd2;

	fdout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fdout == -1)
		sys_error();
	cmd_w_opt = ft_split(av[2], ' ');
	if (cmd_w_opt == NULL)
		sys_error();
	cmd2 = get_cmd_path(cmd_w_opt[0], env);
	if (cmd2 == NULL)
		prg_error("pipex: command not found\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	execve(cmd2, cmd_w_opt, env);
}

void cmd_1_exec(char **av, char **env, int *fd)
{
	int fdin;
	char **cmd_w_opt;
	char *cmd1;

	fdin = open(av[1], O_RDONLY, 0777);
	if (fdin == -1)
		sys_error();
	cmd_w_opt = ft_split(av[2], ' ');
	if (cmd_w_opt == NULL)
		sys_error();
	if (cmd_w_opt[0][0] == '/')
		cmd1 = ft_strdup(cmd_w_opt[0]);
	else
		cmd1 = get_cmd_path(cmd_w_opt[0], env);
	if (cmd1 == NULL)
		prg_error("pipex: command not found\n");
	dup2(fdin, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execve(cmd1, cmd_w_opt, env);
}