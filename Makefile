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
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include/

PATH_UTILS = $(addprefix $(DIR_UTILS), $(SRCS_UTILS))
DIR_UTILS = utils/
SRCS_UTILS = utils.c\

SRCS = $(PATH_UTILS) $(ORIGIN)
OBJS = $(SRCS:.c=.o)

# RULES
all: $(NAME)

libft:
	@make -C ./include/libft

$(NAME): $(OBJS) libft
	@$(CC) -I ./include $(OBJS) ./include/libft/libft.a $(CFLAGS) -o $(NAME)
	@echo "$(COLOUR_MAGENTA)objs & $(NAME) generate 🌸$(END_COLOR)"

run: libft
	@$(CC) -I ./include $(SRCS) ./include/libft/libft.a $(CFLAGS) -o $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) generate 🍀$(END_COLOR)"

clean:
	@cd ./include/libft; make clean
	@rm -rf $(OBJS)
	@echo "$(COLOUR_BLUE) clean 🐟$(END_COLOR)"

fclean : clean
	@cd ./include/libft && make fclean
	@rm -rf $(NAME)
	@echo "$(COLOUR_BLUE) fclean 🐳$(END_COLOR)"

re:fclean all
	@echo "$(COLOUR_MAGENTA)make re OK 🌸$(END_COLOR)"

.PHONY: all clean fclean re run libft
