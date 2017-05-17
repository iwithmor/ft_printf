# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 20:21:24 by iwithmor          #+#    #+#              #
#    Updated: 2017/01/15 20:21:26 by iwithmor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LDIR = ./libft
INCLUDE = -I. -I$(LDIR)

SRC = ft_printf.c
SRC += formats.c
SRC += print_type.c
SRC += flags.c
SRC += width.c
SRC += precision.c
SRC += length.c
SRC += specifier.c
SRC += error.c
SRC += stuff.c
SRC += incompatible.c
SRC += negative_hex.c
SRC += unsigned.c
SRC += signed.c
SRC += print_unsigned.c
SRC += print_signed.c
SRC += print_string.c

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(LDIR)/ft_memset.o $(LDIR)/ft_bzero.o $(LDIR)/ft_memcpy.o \
$(LDIR)/ft_memccpy.o $(LDIR)/ft_memmove.o $(LDIR)/ft_memchr.o \
$(LDIR)/ft_memcmp.o $(LDIR)/ft_strlen.o $(LDIR)/ft_strdup.o \
$(LDIR)/ft_strcpy.o $(LDIR)/ft_strncpy.o $(LDIR)/ft_strchr.o \
$(LDIR)/ft_strrchr.o $(LDIR)/ft_strstr.o $(LDIR)/ft_strcat.o \
$(LDIR)/ft_strncat.o $(LDIR)/ft_strlcat.o $(LDIR)/ft_strnstr.o \
$(LDIR)/ft_strcmp.o $(LDIR)/ft_strncmp.o $(LDIR)/ft_atoi.o \
$(LDIR)/ft_isalpha.o $(LDIR)/ft_isdigit.o $(LDIR)/ft_isalnum.o \
$(LDIR)/ft_isascii.o $(LDIR)/ft_isprint.o $(LDIR)/ft_toupper.o \
$(LDIR)/ft_tolower.o $(LDIR)/ft_memalloc.o $(LDIR)/ft_memdel.o \
$(LDIR)/ft_strnew.o $(LDIR)/ft_strdel.o $(LDIR)/ft_strclr.o \
$(LDIR)/ft_striter.o $(LDIR)/ft_striteri.o $(LDIR)/ft_strmap.o \
$(LDIR)/ft_strmapi.o $(LDIR)/ft_strequ.o $(LDIR)/ft_strnequ.o \
$(LDIR)/ft_strsub.o $(LDIR)/ft_strjoin.o $(LDIR)/ft_strtrim.o \
$(LDIR)/ft_strsplit.o $(LDIR)/ft_itoa.o $(LDIR)/ft_putchar.o \
$(LDIR)/ft_putstr.o $(LDIR)/ft_putendl.o $(LDIR)/ft_putnbr.o \
$(LDIR)/ft_putchar_fd.o $(LDIR)/ft_putstr_fd.o $(LDIR)/ft_putendl_fd.o \
$(LDIR)/ft_putnbr_fd.o $(LDIR)/ft_lstnew.o $(LDIR)/ft_lstdelone.o \
$(LDIR)/ft_lstdel.o $(LDIR)/ft_lstadd.o $(LDIR)/ft_lstiter.o \
$(LDIR)/ft_lstmap.o $(LDIR)/get_next_line.o $(LDIR)/ft_contains_digits.o \
$(LDIR)/ft_itoa_base.o $(LDIR)/ft_exponent.o $(LDIR)/ft_factorial.o \
$(LDIR)/ft_swap.o $(LDIR)/ft_lstlen.o $(LDIR)/ft_ultoa_base.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(OBJ_LIBFT)

$(OBJ):
	make -C $(LDIR)
	gcc $(FLAGS) -c $(SRC) $(INCLUDE)

clean:
	make clean -C $(LDIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
