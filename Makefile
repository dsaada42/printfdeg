# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 13:37:43 by dsaada            #+#    #+#              #
#    Updated: 2020/07/22 01:20:19 by dsaada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
ARFLAGS = rc
CFLAGS = -Wall -Wextra 

NAME = libftprintf.a

HEADER = ft_printf.h\
		 converter/ft_convert.h\
		 printer/ft_printer.h\
		 parser/ft_parser.h

SRC = ft_printf.c\
	converter/ft_convert.c\
	converter/ft_convert_utils.c\
	parser/ft_parser.c\
	parser/ft_parser_utils.c\
	parser/ft_parser_utils_2.c\
	printer/ft_print_int.c\
	printer/ft_print_ptr.c\
	printer/ft_printer.c\
	printer/ft_printer_utils.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	make fclean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
