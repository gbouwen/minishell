# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/04 14:19:21 by gbouwen       #+#    #+#                  #
#    Updated: 2020/10/29 14:40:27 by gbouwen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SOURCE_C = get_next_line.c get_next_line_utils.c

SOURCE_O = $(SOURCE_C:.c=.o)

GREEN = \033[38;5;114m
RED = \033[38;5;124m
BLUE = \033[38;5;153m
NORMAL = \033[38;5;255m

all: $(NAME)

%.o: %.c
	@echo "$(GREEN)Created object file:$(NORMAL)	$@"
	@gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME): $(SOURCE_O)
	@echo "$(BLUE)Adding to library...$(NORMAL)"
	@ar rc $(NAME) $(SOURCE_O) $?
	@echo "$(GREEN)Successfully added to library!$(NORMAL)"

clean:
	@echo "$(RED)Removing all .o files...$(NORMAL)"
	@/bin/rm -f $(SOURCE_O) $(BONUS_O)
	@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libgnl.a...$(NORMAL)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)Successfully removed libgnl.a!$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re
