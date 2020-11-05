# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <gbouwen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/29 09:29:26 by gbouwen       #+#    #+#                  #
#    Updated: 2020/11/05 16:48:54 by gbouwen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS =
SOURCE_C =	main.c \
			initialize_free/initialize_data.c \
			initialize_free/initialize_lexer.c \
			initialize_free/free_list_content.c \
			initialize_free/set_env_variables.c \
			read_cmdline/read_cmdline.c \
			lexer/lexer.c \
			lexer/get_char_type.c \
			lexer/state.c \
			lexer/token.c \
			parser/parser.c \
			parser/binary_tree.c \
			parser/cmd_prod.c \
			parser/simple_cmd_prod.c \
			parser/parser_utils.c \
			executer/executer.c \
			executer/command_loop.c \
			builtins/echo.c \
			builtins/cd.c \
			builtins/pwd.c \
			builtins/export.c \
			builtins/export_no_arguments.c \
			builtins/export_variable.c \
			builtins/env.c \
			builtins/exit.c \
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
