/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:10:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/04 08:33:39 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf.h"

#define DELAY	3000

static void	send_bin_one(pid_t server_pid)
{
	kill(server_pid, SIGUSR2);
	usleep(DELAY);
}

static void	send_bin_zero(pid_t server_pid)
{
	kill(server_pid, SIGUSR1);
	usleep(DELAY);
}

static void	send_str_as_binary(const char *str, pid_t server_pid)
{
	unsigned char		i;
	unsigned char		c;
	size_t				len;
	static void (*const	func_ptr[2])(pid_t) = {send_bin_zero, send_bin_one};

	len = ft_strlen(str) + 1;
	while (len)
	{
		i = 0;
		c = *str;
		while (i < 8)
		{
			func_ptr[(c & 1)](server_pid);
			c = c >> 1;
			i++;
		}
		str++;
		len--;
	}
}

int	main(int argc, char const *argv[])
{
	if (argc != 3 || ft_atoi(argv[1]) < 1)
	{
		ft_printf("Usage is:\n./client <server_server_pid> \"<string>\"\n");
		return (1);
	}
	send_str_as_binary(argv[2], ft_atoi(argv[1]));
	return (0);
}
