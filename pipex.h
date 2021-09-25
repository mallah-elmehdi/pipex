
#ifndef PIPEX_H
# define PIPEX_H
# include "util/util.h"
# include <sys/wait.h> 

char    *try_all_paths(char **all_paths, char *cmd);
char    *get_cmd_path(char *cmd, char **env);
void    cmd_2_exec(char **av, char **env, int *fd);
void    cmd_1_exec(char **av, char **env, int *fd);
void    pipex(char **av, char **env, int *fd);

#endif