#include "pipex.h"

// switch the input fd to thr filr file-in
int  main_set_input(char *file)
{
    int fdin;

    fdin = open(file, O_RDONLY);
    if (fdin == ERR)
        return (error("Error: file not found"));
    dup2(fdin, 0);
    return (SUCCESS);
}

// switch the output fd to thr filr file-out
int  main_set_output(char *file)
{
    int fdout;

    fdout = open(file, O_WRONLY);
    if (fdout == ERR)
        return (error("Error: file not found"));
    dup2(fdout, 0);
    return (SUCCESS);
}

int main(int ac, char **av, char **env)
{
    if (ac != 5)
        return (error("Error: wrong number of argument"));
    if (main_set_input(av[1]) == ERR)
        return (ERR);
    if (main_set_output(av[4]) == ERR)
        return (ERR);
    return (SUCCESS);
}