# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 11:14:10 by emallah           #+#    #+#              #
#    Updated: 2021/10/13 11:14:11 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
FLAG = -Wall -Wextra -Werror
UTIL = util/error.c  util/split.c  util/strjoin.c  util/strlen.c  util/strnstr.c util/calloc.c util/strdup.c util/free.c
FILE = ecexution.c cmdpath.c
PPX = pipex.c

$(NAME):
	@gcc -g $(FILE) $(UTIL) $(PPX) -o $(NAME)

all : $(NAME)

clean:
	@rm -fr pipex.dSYM

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all
