# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 07:59:01 by niludwig          #+#    #+#              #
#    Updated: 2017/02/11 17:09:42 by niludwig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAG = -c -Wall -Werror -Wextra
SRC_NAME = ft_printf.c\
		arg_pars.c\
		cast.c\
		colors.c\
		notype.c\
		print_type.c\
		type.c
OBJ_NAME = $(SRC_NAME:.c=.o)
AR = ar rc
RLIB = ranlib
LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a
RM = rm -f

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT_NAME) $(NAME)
	@$(CC) $(CFLAG) $(SRC_NAME)
	@$(AR) $(NAME) $(OBJ_NAME)
	@$(RLIB) $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_NAME)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all
