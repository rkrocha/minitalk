/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/31 11:22:15 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

#define DELAY	500

static void	send_bin_one(pid_t server_pid)
{
	kill(server_pid, SIGUSR2);
}

static void	send_bin_zero(pid_t server_pid)
{
	kill(server_pid, SIGUSR1);
}

static void	send_str_as_binary(const char *str, pid_t server_pid)
{
	unsigned char		i;
	unsigned char		c;
	static void (*const	func_ptr[2])(pid_t) = {send_bin_zero, send_bin_one};

	while (*str)
	{
		i = 0;
		c = *str;
		while (i < 8)
		{
			func_ptr[(c & 0x01)](server_pid);
			c = c >> 1;
			i++;
			usleep(DELAY);
		}
		str++;
	}
	while (i > 0)
	{
		send_bin_zero(server_pid);
		i--;
		usleep(DELAY);
	}
	sleep(1);
	ft_printf("Timed out\n");
}

static void	catch_server_response(int sig_num)
{
	if (sig_num == SIGUSR2)
		return ;
	ft_printf("Server ack: end of transmission\n");
	exit(0);
}

int	main(int argc, char const *argv[])
{
	struct sigaction	act;

	if (argc != 3 || ft_atoi(argv[1]) < 1)
	{
		ft_printf("Usage is:\n./client <server_server_pid> \"<string>\"\n");
		return (1);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = catch_server_response;
	if (sigemptyset(&act.sa_mask) < 0
		|| sigaction(SIGUSR1, &act, NULL) < 0
		|| sigaction(SIGUSR2, &act, NULL) < 0)
		return (1);
	send_str_as_binary(argv[2], ft_atoi(argv[1]));
	return (0);
}
