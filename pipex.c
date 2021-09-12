#include "pipex.h"

// strlen
int ft_strlen(const char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;	
	return (i);
}


// system error
int sys_error()
{
	char *msg;
	
	msg = strerror(errno);
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    return (ERR);
}

// programme error
int prg_error()
{
    write(2, "Error: Something went wrong!\n", 29);
    return (ERR);
}

// switch the input fd to the file file-in
int  main_set_input(char *file)
{
	int fdin;

	fdin = open(file, O_RDONLY);
	if (fdin == ERR)
		return (sys_error());
	dup2(fdin, 0);
	return (SUCCESS);
}

// switch the output fd to the file file-out
int  main_set_output(char *file)
{
	int fdout;

	fdout = open(file, O_WRONLY | O_CREAT);
	if (fdout == ERR)
		return (sys_error());
	dup2(fdout, 1);
	return (SUCCESS);
}

char *get_path_env(char **env)
{
	char **env_splited;
	char *path;
	int i;
	
	i = 0;
	while (env[i])
	{
		env_splited = ft_split(env[i], '=');
		if (env_splited == NULL)
			return (NULL);
		if ()
		i++;
	}
	return (NULL);
}

// pipex logic
int pipex(char **av, char **env)
{
	char *cmd1;
	char *cmd2;
	char *path;
	
	path = get_path_env(env);
	if (path == NULL)
		return (prg_error());
	// cmd1 = get_cmd_path(av[1], path);
	// if (path == NULL)
	// 	return (prg_error());
	// cmd2 = get_cmd_path(av[4], path);
	// if (path == NULL)
	// 	return (prg_error());
	// return (execute_programme(cmd1, cmd2));
	return (SUCCESS);
}

// main function
int main(int ac, char **av, char **env)
{
	if (ac != 5)
		return (sys_error());
	if (main_set_input(av[1]) == ERR)
		return (ERR);
	if (main_set_output(av[4]) == ERR)
		return (ERR);
	if (pipex(av, env) == ERR)
		return (ERR);
	return (SUCCESS);
}