/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/30 21:52:43 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

#define BUFFER_SIZE	1024

static void	write_and_ack(unsigned char c, pid_t client_pid)
{
	static char	buffer[BUFFER_SIZE];
	static int	len;

	buffer[len] = c;
	len++;
	if (c == '\0' || len == BUFFER_SIZE - 1)
	{
		buffer[len] = '\0';
		write(1, buffer, len);
		len = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR1);
		}
	}
}

static void	bin_to_char(unsigned char bin, pid_t client_pid)
{
	static unsigned char	c;
	static unsigned char	pow;
	static unsigned char	two_pow[8] = {1, 2, 4, 8, 16, 32, 64, 128};

	c += bin * two_pow[pow];
	pow++;
	if (pow == 8)
	{
		write_and_ack(c, client_pid);
		pow = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR2);
}

static void	catch_signals(int sig_num, siginfo_t *info, void *context)
{
	(void)context;
	bin_to_char(sig_num == SIGUSR2, info->si_pid);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = catch_signals;
	if (sigemptyset(&act.sa_mask) < 0
		|| sigaction(SIGUSR1, &act, NULL) < 0
		|| sigaction(SIGUSR2, &act, NULL) < 0)
		return (1);
	ft_printf("Server PID: %u\n", getpid());
	while (1)
		pause();
	return (0);
}
