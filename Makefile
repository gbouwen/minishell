# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <gbouwen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/29 09:29:26 by gbouwen       #+#    #+#                  #
<<<<<<< HEAD
#    Updated: 2020/10/28 15:46:01 by tiemen        ########   odam.nl          #
=======
#    Updated: 2020/10/28 17:04:50 by gbouwen       ########   odam.nl          #
>>>>>>> 05ac120d3152d25eee79c3b5e2e9c9c96bf209c2
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE_C =	main.c \
			lexer/lexer.c \
			lexer/get_char_type.c \
			lexer/state_check.c \
			lexer/state.c \
			lexer/token.c \
			error/error.c

OBJECT_FILES = $(SOURCE_C:.c=.o)
LIBRARIES = -Llibft -lft -Lget_next_line -lgnl -Lft_printf -lftprintf

GREEN = \033[0;38;5;114m
RED = \033[38;5;124m
BLUE = \033[38;5;153m
NORMAL = \033[38;5;255m

all: $(NAME)

%.o: %.c
	@echo "$(GREEN)Created object file:$(NORMAL)	$@"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT_FILES)
	@echo "-----------------------------------"
	@echo "$(GREEN)Compiling libft:$(NORMAL)"
	@make bonus -C libft
	@echo "-----------------------------------"
	@echo "$(GREEN)Compiling get_next_line:$(NORMAL)"
	@make -C get_next_line
	@echo "-----------------------------------"
	@echo "$(GREEN)Compiling ft_printf:$(NORMAL)"
	@make -C ft_printf
	@echo "-----------------------------------"
	@echo "$(BLUE)Created executable:$(NORMAL)	$(NAME)"
	@echo "-----------------------------------"
	@$(CC) $(FLAGS) $(OBJECT_FILES) $(LIBRARIES) -o $(NAME)

clean:
	@echo "$(RED)Removed all .o files$(NORMAL)"
	@echo "-----------------------------------"
	@make clean -C libft
	@make clean -C get_next_line
	@make clean -C ft_printf
	@/bin/rm -f $(OBJECT_FILES)

fclean: clean
	@echo "$(RED)Removed executable:$(NORMAL)	$(NAME)"
	@echo "-----------------------------------"
	@make fclean -C libft
	@make fclean -C get_next_line
	@make fclean -C ft_printf
	@/bin/rm -f $(NAME)

re: fclean all

push: fclean
	git add .
	git commit -m "quick push from makefile"
	git push
