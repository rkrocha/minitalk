/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/29 11:09:28 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

#define DELAY	75

static void	write_and_ack(unsigned char *c, pid_t client_pid)
{
	write(1, c, 1);
	if (*c == '\0')
	{
		kill(client_pid, SIGUSR1);
		write(1, "\n", 1);
		return ;
	}
}

static void	bin_to_char(char bin, pid_t client_pid)
{
	static unsigned char	c;
	static unsigned char	pow;
	static unsigned char	two_pow[8] = {1, 2, 4, 8, 16, 32, 64, 128};

	c = c + (bin * two_pow[pow]);
	pow++;
	if (pow == 8)
	{
		write_and_ack(&c, client_pid);
		pow = 0;
		c = 0;
	}
	usleep(DELAY);
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
