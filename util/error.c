#include "util.h"

int sys_error(const char *extra_msg)
{
	char *msg;
	
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

int prg_error(const char *err, char **cmd_w_opt)
{
    write(2, err, ft_strlen(err));
    if (cmd_w_opt)
    {
        write(2, cmd_w_opt[0], ft_strlen(cmd_w_opt[0]));
        write(2, "\n", 1);
        free_double(cmd_w_opt);
    }
    exit(EXIT_FAILURE);
}