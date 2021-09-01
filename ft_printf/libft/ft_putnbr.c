/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:27:11 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:13:48 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + 48);
}
