# COLOR MAKEFILE
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;36m
COLOUR_YELLOW = \033[0;93m
COLOUR_MAGENTA = \033[0;95m
END_COLOR=\033[0m

# VAR
NAME = philo
ORIGIN = main.c
CC = cc
SRC_PATH	:= src/
OBJ_PATH 	:= .obj/

CFLAGS = -Wall -Wextra -Werror -I ./include
CFLAGS = -Wall -Wextra -Werror -I./include/

# DEBUG
DCFLAGS_VAL = $(CFLAGS) -g
DCFLAGS_FSA = $(CFLAGS) -g3 -fsanitize=address

# FOLDER & FILES
# PATH_DEV = $(addprefix $(DIR_X), $(SRCS_Y))
# DIR_DEV = FOLDER/
# SRCS_DEV = FILE.c \

# FILES = $(PATH_X)
FILES = $(ORIGIN)

SRCS := $(addprefix $(SRC_PATH), $(FILES))
OBJS := $(subst $(SRC_PATH), $(OBJ_PATH), $(SRCS:.c=.o))

# RULES
all: $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "compiling : $<                                      \r"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(COLOR_MAGENTA)objs & $(NAME) generate 🌸$(END_COLOR)"

run:
	@echo "$(COLOR_GREEN)$(NAME) generate 🍀$(END_COLOR)"

# Debug
debugv : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	valgrind --leak-check=full ./minishell

debugfa: run
	@$(CC) $(DCFLAGS_FSA) -g3 -fsanitize=address $(SRCS) -o $(NAME)
	./$(NAME)

the_end :
	rm -rf $(OBJS)
	rm -rf $(NAME)
	rm -rf boite_a_outils
	rm -rf a.out
	rm -rf for_dev

# Clean
clean:
	@rm -rf $(OBJS)
	@echo "$(COLOUR_BLUE) clean 🐟$(END_COLOR)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(COLOUR_BLUE) fclean 🐳$(END_COLOR)"

re:fclean all
	@echo "$(COLOUR_MAGENTA)make re OK 🌸$(END_COLOR)"

.PHONY: all clean fclean re run debugv debugfa the_end
