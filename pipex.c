#include "pipex.h"

void pipex(char **av, char **env, int *fd)
{
	int pid;
	
	pid = fork();
	if (pid == -1)
		sys_error();
	if (pid == 0)
		cmd_1_exec(av, env, fd);
	waitpid(pid, NULL, 0);
	cmd_2_exec(av, env, fd);	
}

int main(int ac, char **av, char **env)
{
	int fd[2];
	
	if (ac != 5)
		prg_error("pipex: wrong number of arguments!\n");
	if (pipe(fd) == -1)
		sys_error();
	pipex(av, env, fd);
	close(fd[0]);
	close(fd[1]);
	return (EXIT_SUCCESS);
}