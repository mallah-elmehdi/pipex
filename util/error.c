#include "util.h"

int sys_error()
{
	char *msg;
	
	msg = strerror(errno);
    write(2, "pipex: ", ft_strlen("pipex: "));
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

int prg_error(const char *err)
{
    write(2, err, ft_strlen(err));
    exit(EXIT_FAILURE);
}