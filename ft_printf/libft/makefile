# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:08:38 by rkochhan          #+#    #+#              #
#    Updated: 2020/12/08 10:35:09 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		=  ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

BONUS	= ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c	\
			ft_lstnew.c \
			ft_lstsize.c

OTHERS	= ft_atof.c \
			ft_isspace.c \
			ft_putchar.c \
			ft_putendl.c \
			ft_putlnbr.c \
			ft_putlnbr_base.c \
			ft_putnbr.c \
			ft_putnstr.c \
			ft_putstr.c \
			ft_split_free.c \
			ft_str_remove_blanks.c \
			ft_str_word_count.c \
			ft_strdel.c \
			ft_strignore.c \
			ft_strsearch.c \
			ft_strswap.c \
			ft_ullitoa_base.c \

OBJ		= $(SRC:.c=.o)

BOBJ	= $(BONUS:.c=.o)

OOBJ	= $(OTHERS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(BOBJ) $(OOBJ)
	@ ar rc $(NAME) $(OBJ) $(BOBJ) $(OOBJ)
	@ ranlib $(NAME)
	@ echo "Made $(value NAME)"

all: $(NAME)

clean:
	@ rm -f $(OBJ) $(BOBJ) $(OOBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
