# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 09:26:56 by rkochhan          #+#    #+#              #
#    Updated: 2021/08/24 08:57:09 by rkochhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

SERVER_NAME	= server
SERVER_SRC	= server.c
SERVER_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT_NAME	= client
CLIENT_SRC	= client.c
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)

FT_PRINTF	= ./ft_printf/
LIBFT		= ./ft_printf/libft/
INCLUDE		= -I. -I$(LIBFT) -I$(FT_PRINTF)
LIBS		= -L$(FT_PRINTF) -lftprintf

CC		= clang

C_FLAGS	= -Wall -Werror -Wextra

.c.o:
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
	@ make -s -C $(FT_PRINTF)
	@ $(CC) $(C_FLAGS) $(SERVER_OBJ) $(INCLUDE) $(LIBS) -o $(SERVER_NAME)
	@ echo "Made $(value SERVER_NAME)"

$(CLIENT_NAME): $(CLIENT_OBJ)
	@ make -s -C $(FT_PRINTF)
	@ $(CC) $(C_FLAGS) $(CLIENT_OBJ) $(INCLUDE) $(LIBS) -o $(CLIENT_NAME)
	@ echo "Made $(value CLIENT_NAME)"

all: $(NAME)

clean:
	@ make -s clean -C $(FT_PRINTF)
	@ rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@ make -s fclean -C $(FT_PRINTF)
	@ rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
