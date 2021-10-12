#include "pipex.h"

void cmd_2_exec(char **av, char **env, int *fd)
{
	int fdout;
	char **cmd_w_opt;
	char *cmd2;

	fdout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf("%d\n", fdout);
	if (fdout == -1)
		sys_error(av[4]);
	cmd_w_opt = ft_split(av[3], ' ');
	if (cmd_w_opt == NULL)
		sys_error(NULL);
	cmd2 = get_cmd_path(cmd_w_opt[0], env);
	if (cmd2 == NULL)
		prg_error("pipex: command not found: ",  cmd_w_opt);
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	execve(cmd2, cmd_w_opt, env);
	free_double(cmd_w_opt);
	free(cmd2);
}

void cmd_1_exec(char **av, char **env, int *fd)
{
	int fdin;
	char **cmd_w_opt;
	char *cmd1;

	fdin = open(av[1], O_RDONLY, 0777);
	printf("%d\n", fdin);
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
	execve(cmd1, cmd_w_opt, env);
	free_double(cmd_w_opt);
	free(cmd1);
}