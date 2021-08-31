# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 09:26:56 by rkochhan          #+#    #+#              #
#    Updated: 2021/08/31 11:15:11 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

FT_PRINTF	= ft_printf
LIBFT		= ft_printf/libft
INCLUDE		= -I. -I$(LIBFT) -I$(FT_PRINTF)
LIBS		= -L$(FT_PRINTF) -lftprintf

CC		= clang

C_FLAGS	= -Wall -Werror -Wextra


.c.o:
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): server client

server: server.o
	@ make -s -C $(FT_PRINTF)
	@ $(CC) $(C_FLAGS) server.o $(INCLUDE) $(LIBS) -o server
	@ echo "Made server"

client: client.o
	@ make -s -C $(FT_PRINTF)
	@ $(CC) $(C_FLAGS) client.o $(INCLUDE) $(LIBS) -o client
	@ echo "Made client"


bonus: server_bonus client_bonus

server_bonus: server_bonus.o
	@ make -s -C $(FT_PRINTF)
	@ $(CC) $(C_FLAGS) server_bonus.o $(INCLUDE) $(LIBS) -o server_bonus
	@ echo "Made server_bonus"

client_bonus: client_bonus.o
	@ make -s -C $(FT_PRINTF)
	@ $(CC) $(C_FLAGS) client_bonus.o $(INCLUDE) $(LIBS) -o client_bonus
	@ echo "Made client_bonus"


all: $(NAME)

clean:
	@ make -s clean -C $(FT_PRINTF)
	@ rm -rf server.o client.o server_bonus.o client_bonus.o

fclean: clean
	@ make -s fclean -C $(FT_PRINTF)
	@ rm -rf server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re bonus
