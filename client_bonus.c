/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/29 11:10:23 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

static void	send_bin_one(pid_t server_pid)
{
	kill(server_pid, SIGUSR2);
	ft_putchar('1');
}

static void	send_bin_zero(pid_t server_pid)
{
	kill(server_pid, SIGUSR1);
	ft_putchar('0');
}

static void	send_str_as_binary(const char *str, pid_t server_pid)
{
	unsigned char			i;
	unsigned char			c;
	static	void (*const	func_ptr[2])(pid_t) = {send_bin_zero, send_bin_one};

	while (*str)
	{
		i = 1;
		c = *str;
		while (i <= 8)
		{
			func_ptr[(c & 0x01)](server_pid);
			pause();
			c = c >> 1;
			i++;
		}
		str++;
	}
	while (i > 1)
	{
		send_bin_zero(server_pid);
		pause();
		i--;
	}
}

static void	end_of_transmission(int unused)
{
	(void)unused;
	ft_putstr("Server ACK\n");
	exit(0);
}

static void	unpause(int unused)
{
	(void)unused;
	ft_putchar('x');
}

int	main(int argc, char const *argv[])
{
	if (argc != 3 || ft_atoi(argv[1]) < 1)
	{
		ft_printf("Usage is:\n./client <server_server_pid> \"<string>\"\n");
		return (1);
	}

	// struct sigaction	act;
	// act.sa_flags = SA_SIGINFO;
	// act.sa_handler = unpause;
	// if (sigemptyset(&act.sa_mask) < 0
	// 	|| sigaction(SIGUSR1, &act, NULL) < 0
	// 	|| sigaction(SIGUSR2, &act, NULL) < 0)
	// 	return (1);

	signal(SIGUSR1, end_of_transmission);
	signal(SIGUSR2, unpause);
	send_str_as_binary(argv[2], ft_atoi(argv[1]));
	return (0);
}
