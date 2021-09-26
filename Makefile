
NAME = pipex
FLAG = -Wall -Wextra -Werror
UTIL = util/error.c  util/split.c  util/strjoin.c  util/strlen.c  util/strnstr.c util/calloc.c util/strdup.c util/free.c
FILE = ecexution.c cmdpath.c
PPX = pipex.c

$(NAME):
	@gcc $(FILE) $(UTIL) $(PPX) -o $(NAME)

all : $(NAME)

clean:
	@rm -fr pipex.dSYM

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all