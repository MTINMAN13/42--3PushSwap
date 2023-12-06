NAME = pushswap

# PushSwap shows and illuminates real importance of immediate testing
# Functions need to trully work on their own, creating a main for these
# is invaluable, otherwise bugfixing takes agessssss

DEF_COLOR = \033[0;39m
CLR2 = \033[0;36m
CLR1 = \033[0;37m

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC = push_swap.c
OBJ = $(SRC_S:.c=.o)

LIBFT = libft.a

%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@

all :	pswp
# 		@norminette push_swap.c push_swap.h

test :	all
		clear
		./pushswap 600 594 066 32 984 2000 50000 45 65 98989

pswp:	libft $(OBJ)
		@ $(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)
		@echo "$(CLR2)rdy$(DEF_COLOR)"

libft:
		@ make -C libft/

clean:
		@ $(RM) $(OBJ)
		@ $(RM) $(NAME)
		@echo "$(CLR1)               pushswap wiped! have a nice day ;-)$(DEF_COLOR)"
		@echo "$(CLR2)               please recompile to proceed.$(DEF_COLOR)"
		@sleep 1

fclean: clean
		@ $(RM) $(NAME)
		@ $(RM) libft.a
		@ make -C libft/ clean
		@clear
		@echo "$(CLR1)               all wiped boss! have a nice day ;-)$(DEF_COLOR)"
		@sleep 1
		@clear

re: fclean all

norm:
		@clear
		@norminette push_swap.c push_swap.h

.PHONY: all libft clean fclean re norm pswp
