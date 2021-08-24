/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/24 09:12:29 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

#define SAFETY_DELAY	50

static void	send_bin_one(int pid)
{
	kill(pid, SIGUSR2);
}

static void	send_bin_zero(int pid)
{
	kill(pid, SIGUSR1);
}

static void	send_str_as_binary(const char *str, int pid)
{
	unsigned char			i;
	unsigned char			chr;
	static	void (*const	func_ptr[2])(int) = {send_bin_zero, send_bin_one};

	while (*str)
	{
		i = 1;
		chr = *str;
		while (i <= 8)
		{
			func_ptr[(chr & 0x01)](pid);
			usleep(SAFETY_DELAY);
			chr = chr >> 1;
			i++;
		}
		str++;
	}
}

int	main(int argc, char const *argv[])
{
	if (argc != 3 || ft_atoi(argv[1]) < 1)
		return (1);
	send_str_as_binary(argv[2], ft_atoi(argv[1]));
	return (0);
}
