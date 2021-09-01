/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:55:17 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:19:51 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr_base(long num, char *base, int radix)
{
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= radix)
		ft_putlnbr_base(num / radix, base, radix);
	ft_putchar(base[num % radix]);
}
