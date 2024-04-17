NAME = push_swap
DEF_COLOR = \033[0;39m
CLR2 = \033[0;36m
CLR1 = \033[0;37m

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# Directories
SRC_DIR =
OBJ_DIR = obj/
INCLUDE = include

# Sources
SRC_FILES = push_swap push_a_initiate_stack push_error_handling push_a_start \
			push_performone push_performtwo push_perform_moves push_algo_execute \
			push_a_utils push_a_utils2 push_a_utils3 push_a_utils_cleanups \
			push_struct \
			push_algo_find

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

LIBFT = libft.a

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)  # Create the directory if it doesn't exist
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# Rule to build the executable
$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)
# @clear
	@echo "$(CLR2)rdy$(DEF_COLOR)"
all:	$(NAME)

libft:
		@ make -C libft/

norm:
		@clear
		norminette $(SRC)

clean:
		@ $(RM) $(OBJ)
		@ $(RM) $(OBJ)
		@ $(RM) $(NAME)
		@echo "$(CLR1)        pushswap wiped! have a nice day ;-)$(DEF_COLOR)"
		@echo "$(CLR2)        please recompile to proceed.$(DEF_COLOR)"
		@sleep 1

fclean: clean
		@ $(RM) $(NAME)
		@ $(RM) libft.a
		@ make -C libft/ clean
		@clear
		@echo "$(CLR1)        all wiped boss! have a nice day ;-)$(DEF_COLOR)"
		@sleep 1
		@clear

re: fclean all $(NAME)
	@sleep 1

.PHONY: all libft clean fclean re norm pswp test t_desc t_5 t_6 t_7 t_50 t_101 t_t

test :	$(NAME)
		clear
		./$(NAME) 600 594 66 32 984 2000 50000 45 65 98989 | ./checker_linux 600 594 66 32 984 2000 50000 45 65 98989

t_desc :$(NAME)
		clear
		./$(NAME) 4 3 2

t_5	 :	$(NAME)
		clear
		./$(NAME) 25 9 31 35 42

random_number = $$(echo $$((1 + $$RANDOM % 163)))

t_6	 :	$(NAME)
		clear
		./$(NAME) 25 38 5 6 14 15

t_7	 :	$(NAME)
		clear
		./$(NAME) 681 395 164 3477 31 805 367 45 46 4568 45687848

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all -s

t_50: $(NAME)
	clear
	$(VALGRIND) ./$(NAME) 8 26 73 94 57 15 42 69 53 61 79 32 18 47 83 27 13 68 91 23 36 49 63 75 12 88 41 65 98 22 38 71 51 87 45 29 72 59 81 17 76 54 39 64 95 34 74 21 14 58 33 66 93 384 219 573 862 135 746 298 457 621 934 107 652 789 423 556 193 840 675 321 480 742 599 268 916 105 738 492 653 827 364 529 178 615 754 289 431 567 802 146 687 249 913 374 545 699 835 412 584 731

t_101 :	$(NAME)
		clear
		./push_swap 8 26 73 94 57 15 42 69 53 61 79 32 18 47 83 27 13 68 91 23 36 49 63 75 12 88 41 65 98 22 38 71 51 87 45 29 72 59 81 17 76 54 39 64 95 34 74 21 14 58 33 66 93 384 219 573 862 135 746 298 457 621 934 107 652 789 423 556 193 840 675 321 480 742 599 268 916 105 738 492 653 827 364 529 178 615 754 289 431 567 802 146 687 249 913 374 545 699 835 412 584 731

t_102 :	$(NAME)
		clear
		./push_swap 8 26 73 94 57 15 42 69 53 61 79 32 18 47 83 27 13 68 91 23 36 49 63 75 12 88 41 65 98 22 38 71 51 87 45 29 72 59 81 17 76 54 39 64 95 34 74 21 14 58 33 66 93 384 219 573 862 135 746 298 457 621 934 107 652 789 423 556 193 840 675 321 480 742 599 268 916 105 738 492 653 827 364 529 178 615 754 289 431 567 802 146 687 249 913 374 545 699 835 412 584 731  | wc -l


t_t	 :	$(NAME)
		clear
		./$(NAME) $(call random_number) $(call random_number) $(call random_number) $(call random_number) $(call random_number) $(call random_number) $(call random_number) $(call random_number) $(call random_number)
