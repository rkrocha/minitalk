/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:48:33 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 11:05:22 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr(long num)
{
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		ft_putlnbr(num / 10);
	ft_putchar(num % 10 + 48);
}
