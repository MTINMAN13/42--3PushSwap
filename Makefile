NAME = pushswap
DEF_COLOR = \033[0;39m
CLR2 = \033[0;36m
CLR1 = \033[0;37m

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# Directories
SRC_DIR =
OBJ_DIR = obj
INCLUDE = include

# Sources
SRC_FILES = push_swap push_a_initiate_stack push_error_handling push_a_start \
			push_performone push_performtwo push_perform_moves push_algo_execute \
			push_a_utils

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

LIBFT = libft.a

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# Rule to build the executable
$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)
	@clear
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

re: fclean all pushswap
	@sleep 1

norm:
		@clear
		@norminette push_swap.c push_swap.h

.PHONY: all libft clean fclean re norm pswp

test :	pushswap
		clear
		./pushswap 600 594 066 32 984 2000 50000 45 65 98989 asd wtf ixd

t_desc :pushswap
		clear
		./pushswap 4 3 2

t_t	 :	pushswap
		clear
		./pushswap 364 32479 83572203 85 36
