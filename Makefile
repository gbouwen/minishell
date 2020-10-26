# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <gbouwen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/29 09:29:26 by gbouwen       #+#    #+#                  #
#    Updated: 2020/10/19 13:35:07 by gbouwen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE_CPP = main.cpp get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJECT_FILES = $(SOURCE_C:.c=.o)

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
	@echo "$(BLUE)Created executable:$(NORMAL)	$(NAME)"
	@echo "-----------------------------------"
	@$(CC) $(FLAGS) $(OBJECT_FILES) -o $(NAME)

clean:
	@echo "$(RED)Removed all .o files$(NORMAL)"
	@echo "-----------------------------------"
	@/bin/rm -f $(OBJECT_FILES)

fclean: clean
	@echo "$(RED)Removed executable:$(NORMAL)	$(NAME)"
	@echo "-----------------------------------"
	@/bin/rm -f $(NAME)

re: fclean all
