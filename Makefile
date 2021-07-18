
NAME = pipex
FLAG =  -Wall -Wextra -Werror
FILE = util.c
PPX =  pipex.c

$(NAME):
	@gcc $(FILE) $(PPX) -o $(NAME)

all : $(NAME)

clean:
	@rm -fr pipex.dSYM

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all