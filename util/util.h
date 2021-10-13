/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:13:44 by emallah           #+#    #+#             */
/*   Updated: 2021/10/13 11:13:46 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		sys_error(const char *extra_msg);
int		prg_error(const char *err, char **cmd_w_opt);
int		delim_length(char const *str, char delim);
char	**free_splited_str(char **splited_str, int i);
char	**ft_split(const char *str, char delim);
size_t	lenth(const char *s, const char *s0);
char	*ft_strjoin(const char *s, const char *s0);
int		ft_strlen(const char *str);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
void	*ft_calloc(size_t a, size_t b);
char	*ft_strdup(const char *str);
void	free_double(char **double_ptr);
char	*fill_str(const char *str, char delim, int part);
#endif
