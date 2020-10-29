# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/09 14:43:41 by gbouwen       #+#    #+#                  #
#    Updated: 2020/10/29 14:31:14 by gbouwen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE_FILES =	ft_printf.c utils_struct.c check_flags.c check_conversions.c \
		   		utils_print.c utils_print_2.c get_len.c print_d_i.c \
				print_u.c print_x.c print_p.c print_rest.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

GREEN = \033[0;38;5;114m
RED = \033[38;5;124m
BLUE = \033[38;5;153m
NORMAL = \033[38;5;255m

all: $(NAME)

%.o: %.c
	@echo "$(GREEN)Created object file:$(NORMAL)	$@"
	@gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME): $(OBJECT_FILES)
	@echo "$(BLUE)Adding to library...$(NORMAL)"
	@ar rc $(NAME) $(OBJECT_FILES)
	@echo "$(GREEN)Successfully added to library!$(NORMAL)"

clean:
	@echo "$(RED)Removing all .o files...$(NORMAL)"
	@/bin/rm -f $(OBJECT_FILES)
	@echo "$(GREEN)Succesfully removed all object files!"

fclean: clean
	@echo "$(RED)Removing libftprintf.a...$(NORMAL)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)Successfully removed library!$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re
