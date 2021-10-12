#include "pipex.h"

void pipex(char **av, char **env, int *fd)
{
	int pid;
	int status = 0;
	int status_ex = 0;

	pid = fork();
	if (pid == -1)
		sys_error(NULL);
	if (pid == 0)
		cmd_1_exec(av, env, fd);

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		status_ex  = WTERMSIG(status) % 128;
	if (WIFEXITED(status))
		status_ex  = WEXITSTATUS(status);
		
		printf("%d\n", status_ex);
	
	if (status == 199)
		exit(30);
	// pid = fork();
	// if (pid == -1)
	// 	sys_error(NULL);
	// if (pid == 0)
	// 	cmd_2_exec(av, env, fd);
	// waitpid(pid, NULL, 0);
}

int main(int ac, char **av, char **env)
{
	int fd[2];

	if (ac != 5)
		prg_error("pipex: wrong number of arguments!\n", NULL);
	if (pipe(fd) == -1)
		sys_error(NULL);
	pipex(av, env, fd);
	close(fd[0]);
	close(fd[1]);
	return (EXIT_SUCCESS);
}