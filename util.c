#include "pipex.h"

// ===== error handler
int error(const char *err)
{
    perror(err);
    return (ERR);
}