#!/bin/sh

gcc -Wall -Werror -Wextra -fsanitize=address -g main_debug.c ft_printf*.c -I. -I./libft/ -L./libft/ -lft -o ft_printf && ./ft_printf
