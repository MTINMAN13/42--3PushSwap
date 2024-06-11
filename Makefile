NAME = push_swap
NAME_BONUS = checker

#########################        LIBS        #################################

NAMELIB = srcs/push_swap.a
LIBFT = libft.a
OBJ_DIR = obj
INCLUDE = include

##########################    DIRS     ####################################

SRC_DIR = srcs

###########################    FILES   ####################################

MAIN = $(SRC_DIR)/main.c
SRC = $(SRC_DIR)/utils.c $(SRC_DIR)/parse.c $(SRC_DIR)/setinit.c \
      $(SRC_DIR)/handle_nodes.c $(SRC_DIR)/moves_swpu.c $(SRC_DIR)/moves_rr.c \
      $(SRC_DIR)/sort.c $(SRC_DIR)/set_position.c $(SRC_DIR)/set_distance.c \
      $(SRC_DIR)/sort_small.c
SRC_FILES = $(MAIN) $(SRC)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

##########################   COMPILING SETTINGS   #########################

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Llibft -lft
RM = rm -f

###########################    EXTRAS   ####################################

NOC = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
DEF_COLOR = \033[0;39m
CLR2 = \033[0;36m
CLR1 = \033[0;37m

###########################    BUILD   ####################################

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_FILES) libft
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LIBFT)
	@echo "$(CLR2)Ready$(DEF_COLOR)"

all: $(NAME)

libft:
	@make -C libft/

norm:
	@clear
	norminette $(SRC_FILES)

clean:
	@$(RM) $(OBJ_FILES)
	@$(RM) $(NAME)
	@echo "$(CLR1)push_swap cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(LIBFT)
	@make -C libft/ clean
	@clear
	@echo "$(CLR1)All cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY: all libft clean fclean re norm test t_desc t_5 t_6 t_7 t_50 t_101 t_102 t_t

test: $(NAME)
	clear
	./$(NAME) 600 594 66 32 984 2000 50000 45 65 98989 | ./checker_linux 600 594 66 32 984 2000 50000 45 65 98989

t_desc: $(NAME)
	clear
	./$(NAME) 4 3 2

t_5: $(NAME)
	clear
	./$(NAME) 25 9 31 35 42

t_6: $(NAME)
	clear
	./$(NAME) 25 38 5 6 14 15

t_7: $(NAME)
	clear
	./$(NAME) 681 395 164 3477 31 805 367 45 46 4568 45687848

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all -s

t_50: $(NAME)
	clear
	$(VALGRIND) ./$(NAME) 8 26 73 94 57 15 42 69 53 61 79 32 18 47 83 27 13 68 91 23 36 49 63 75 12 88 41 65 98 22 38 71 51 87 45 29 72 59 81 17 76 54 39 64 95 34 74 21 14 58 33 66 93 384 219 573 862 135 746 298 457 621 934 107 652 789 423 556 193 840 675 321 480 742 599 268 916 105 738 492 653 827 364 529 178 615 754 289 431 567 802 146 687 249 913 374 545 699 835 412 584 731

t_101: $(NAME)
	clear
	./$(NAME) 8 26 73 94 57 15 42 69 53 61 79 32 18 47 83 27 13 68 91 23 36 49 63 75 12 88 41 65 98 22 38 71 51 87 45 29 72 59 81 17 76 54 39 64 95 34 74 21 14 58 33 66 93 384 219 573 862 135 746 298 457 621 934 107 652 789 423 556 193 840 675 321 480 742 599 268 916 105 738 492 653 827 364 529 178 615 754 289 431 567 802 146 687 249 913 374 545 699 835 412 584 731

t_102: $(NAME)
	clear
	./$(NAME) 8 26 73 94 57 15 42 69 53 61 79 32 18 47 83 27 13 68 91 23 36 49 63 75 12 88 41 65 98 22 38 71 51 87 45 29 72 59 81 17 76 54 39 64 95 34 74 21 14 58 33 66 93 384 219 573 862 135 746 298 457 621 934 107 652 789 423 556 193 840 675 321 480 742 599 268 916 105 738 492 653 827 364 529 178 615 754 289 431 567 802 146 687 249 913 374 545 699 835 412 584 731 | wc -l

t_t: $(NAME)
	clear
	./$(NAME) $(random_number) $(random_number) $(random_number) $(random_number) $(random_number) $(random_number) $(random_number) $(random_number) $(random_number)
