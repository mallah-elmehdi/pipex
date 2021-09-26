#include "pipex.h"

char *try_all_paths(char **all_paths, char *cmd)
{
	int i;
	char *path_w_slash;
	char *candidate_path;

	i = 0;
	while (all_paths[i])
	{
		path_w_slash = ft_strjoin(all_paths[i], "/");
		if (path_w_slash == NULL)
			sys_error(NULL);
		candidate_path = ft_strjoin(path_w_slash, cmd);
		free(path_w_slash);
		if (candidate_path == NULL)
			sys_error(NULL);
		if (access(candidate_path, F_OK) == 0)
			return (candidate_path);
		free(candidate_path);
		i++;
	}
	return (NULL);
}

char *get_cmd_path(char *cmd, char **env)
{
	char **all_paths;
	char *cmd_path;
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			all_paths = ft_split(env[i] + 5, ':');
			if (all_paths == NULL)
				sys_error(NULL);
			break;
		}
		i++;
	}
	cmd_path = try_all_paths(all_paths, cmd);
	free_double(all_paths);
	return (cmd_path);
}