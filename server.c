/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/24 00:12:18 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

static unsigned char	two_pow(unsigned char pow)
{
	unsigned char	result;

	if (pow == 0)
		return (1);
	result = 2;
	pow--;
	while (pow)
	{
		result = result * 2;
		pow--;
	}
	return (result);
}

static void	bin_to_char(char bin)
{
	static unsigned char	c;
	static unsigned char	pow;

	c = c + (bin * two_pow(pow));
	pow++;
	if (pow == 8)
	{
		ft_putchar(c);
		pow = 0;
		c = 0;
	}
}

static void	catch_bin_one(int sig_num)
{
	signal(SIGUSR2, catch_bin_one);
	bin_to_char(1);
	(void)sig_num;
}

static void	catch_bin_zero(int sig_num)
{
	signal(SIGUSR1, catch_bin_zero);
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
