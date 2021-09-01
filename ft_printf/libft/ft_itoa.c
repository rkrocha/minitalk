/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:23:07 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:02:47 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_len(long num)
{
	size_t	len;

	len = 1;
	if (num < 0)
		len++;
	while ((num / 10) != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;
	size_t	i;

	num = n;
	len = itoa_len(num);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
		i++;
	}
	while (len > i)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}
