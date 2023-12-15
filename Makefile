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
DCFLAGS_FST = $(CFLAGS) -g3 -fsanitize=thread

# FOLDER & FILES

SRCS_FILES = parsing.c fn_libft.c utils.c init.c the_meal.c philo_routine.c philo_life.c clean.c\
#generate_philo.c routine.c check_dead_alive.c \

# PATH_DEV = $(addprefix $(DIR_X), $(SRCS_Y))
# DIR_DEV = FOLDER/
# SRCS_DEV = FILE.c

# FILES = $(PATH_X)
FILES =  $(PATH_UTILS) $(SRCS_FILES) $(ORIGIN)

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

# Debug
debugv : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	valgrind --leak-check=full ./philo 1 800 200 200

debugfa: run
	@$(CC) $(DCFLAGS_FSA) -g3 -fsanitize=address $(SRCS) -o $(NAME)

debugft: run
	@$(CC) $(DCFLAGS_FST) $(SRCS) -o $(NAME)

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
