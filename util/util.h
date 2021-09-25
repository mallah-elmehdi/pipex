
#ifndef UTIL_H
# define UTIL_H
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int     sys_error();
int     prg_error(const char *err);
int			delim_length(char const *str, char delim);
char		**free_splited_str(char **splited_str, int i);
char		**ft_split(const char *str, char delim);
size_t  lenth(const char *s, const char *s0);
char    *ft_strjoin(const char *s, const char *s0);
int     ft_strlen(const char *str);
char    *ft_strnstr(const char *str1, const char *str2, size_t n);
void	*ft_calloc(size_t a, size_t b);
char    *ft_strdup(const char *str);

#endif