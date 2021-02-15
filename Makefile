# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <gbouwen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/29 09:29:26 by gbouwen       #+#    #+#                  #
#    Updated: 2021/02/15 13:33:42 by tiemen        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE_C =	main.c \
			initialize_free/initialize_data.c \
			initialize_free/initialize_lexer.c \
			initialize_free/free_list_content.c \
			initialize_free/free_struct.c \
			initialize_free/set_env_variables.c \
			initialize_free/free_str_array.c \
			read_cmdline/read_cmdline.c \
			read_cmdline/read_cmdline_utils.c \
			lexer/lexer.c \
			lexer/get_char_type.c \
			lexer/state.c \
			lexer/token.c \
			parser/parser.c \
			parser/binary_tree.c \
			parser/cmd_prod.c \
			parser/task_prod.c \
			parser/sequence_prod.c \
			parser/parser_utils.c \
			executer/executer.c \
			executer/command_loop.c \
			builtins/echo.c \
			builtins/cd.c \
			builtins/pwd.c \
			builtins/export.c \
			builtins/export_no_arguments.c \
			builtins/export_variable.c \
			builtins/unset.c \
			builtins/env.c \
			builtins/exit.c \
			helper_functions/get_str_array_len.c \
			helper_functions/count_tree_arguments.c \
			helper_functions/strjoin_free.c \
			helper_functions/get_work_dir_prompt.c \
			helper_functions/compare_both.c \
			expander/expand_files.c \
			expander/expand_files_pipe.c \
			expander/expand_variables.c \
			expander/strip_quotes_and_spaces_node.c \
			expander/expand_env_variables.c \
			expander/expand_node_content.c \
			expander/expand_node_content_utils.c \
			expander/expand_single_variable.c \
			expander/expand_env_utils.c \
			expander/expand_question_mark.c \
			expander/split_on_spaces.c \
			expander/ambiguous_redirect.c \
			expander/node_add_back.c \
			expander/remove_quotes.c \
			executer/execute_pipe.c \
			executer/execute_pipe_utils.c \
			executer/execute_simple_command.c \
			executer/fork_and_execute.c \
			executer/fork_and_execute_utils.c \
			executer/path_variables.c \
			executer/redirections.c \
			error/error.c \
			error/signals.c

OBJECT_FILES = $(SOURCE_C:.c=.o)
LIBRARIES = -Llibft -lft -Lft_printf -lftprintf

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
	@make clean -C ft_printf
	@/bin/rm -f $(OBJECT_FILES)

fclean: clean
	@echo "$(RED)Removed executable:$(NORMAL)	$(NAME)"
	@echo "-----------------------------------"
	@make fclean -C libft
	@make fclean -C ft_printf
	@/bin/rm -f $(NAME)

re: fclean all

push: fclean
	git add .
	git commit -m "quick push from makefile"
	git push
