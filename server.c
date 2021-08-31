/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/30 21:17:21 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

static void	bin_to_char(unsigned char bin)
{
	static unsigned char	c;
	static unsigned char	pow;
	static unsigned char	two_pow[8] = {1, 2, 4, 8, 16, 32, 64, 128};

	c += bin * two_pow[pow];
	pow++;
	if (pow == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		pow = 0;
		c = 0;
	}
}

static void	catch_bin_one(int sig_num)
{
	bin_to_char(1);
	(void)sig_num;
}

static void	catch_bin_zero(int sig_num)
{
	bin_to_char(0);
	(void)sig_num;
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, catch_bin_zero);
	signal(SIGUSR2, catch_bin_one);
	while (1)
		pause();
	return (0);
}
