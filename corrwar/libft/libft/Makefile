# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 05:34:12 by niludwig          #+#    #+#              #
#    Updated: 2017/02/09 07:16:08 by niludwig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Werror -Wextra
GCC= gcc
SRC= ft_memset.c ft_putchar.c ft_putstr.c ft_bzero.c ft_memcpy.c \
	ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strncat.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	ft_strclr.c ft_striter.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strnequ.c ft_striteri.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_isqrt.c ft_lstpush.c ft_lstchr.c ft_memadd.c \
	ft_lstnew_nc.c ft_realloc.c ft_memdup.c ft_interpolate.c \
	ft_rgb.c ft_itplcolor.c ft_putstr_until.c ft_llitoa.c \
	ft_ullitoa.c ft_putxchar.c ft_ullitoa_base.c ft_binsize.c \
	ft_wcstombs.c ft_putstr_unless.c ft_wcslen.c ft_wcscbytes.c \
	ft_wctomb.c ft_llitob.c ft_strcnt.c ft_charcmp.c ft_lstsort.c \
	ft_maxintstrlen.c ft_intstrlen.c ft_llstsort.c ft_tabstrdel.c \
	ft_tabcnt.c ft_tabstrdup.c ft_tabstrdelall.c ft_tabstrdelx.c \
	ft_strjoind.c get_next_line.c ft_tabstrdupom.c
OBJ=	$(SRC:.c=.o)
NAME= libft.a

all: $(NAME)

$(NAME):
	$(GCC) $(FLAGS) $(SRC) -c
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
re:	fclean all
