##
## EPITECH PROJECT, 2023
## makefile
## File description:
## emacs
##

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = my_ls

SRC =   main.c          \
		src/my_ls.c	     \
		src/basic_ls.c    \
		src/reverse_ls.c   \
		lib/my/my_put_nbr.c \
		lib/my/my_putstr.c   \
		lib/my/my_put_nbru.c  \
		lib/my/my_putchar.c    \
		lib/my/my_strlen.c      \
		lib/my/my_printf.c       \
		lib/my/my_swap.c          \
		lib/my/my_strdup.c         \
		lib/my/my_strcpy.c          \

OBJ =  $(SRC:.c=.o)

CFLAGS = -I ./include -Wall

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@echo -e "$(YELLOW)■-■-■ COMPILATION GOOD ■-■-■$(NC)"
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "$(GREEN)■-■-■-■-■-■ GOOD ■-■-■-■-■$(NC)"

all : $(NAME)

clean :
	rm -f $(OBJ)
	rm -f *~
	rm -f #*#
	@echo -e "$(GREEN)CLEAN$(NC)"

fclean : clean
	@echo -e "$(RED)CLEAN -> $(NAME)...$(NC)"
	rm -f $(NAME)
	@echo -e "$(GREEN)■-■-■-■-■-■-■-■-■-■ GOOD$(NC)"

re : fclean all
