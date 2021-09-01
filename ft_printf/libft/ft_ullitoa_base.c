/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:14:00 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:44:49 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	get_radix(size_t *radix, char *base)
{
	*radix = ft_strlen(base);
	if (*radix < 2)
		return (false);
	return (true);
}

static size_t	ullitoa_len(unsigned long long num, size_t radix)
{
	size_t	len;

	len = 1;
	while ((num / radix) != 0)
	{
		num /= radix;
		len++;
	}
	return (len);
}

char	*ft_ullitoa_base(unsigned long long num, char *base, bool sign)
{
	char	*str;
	size_t	radix;
	size_t	len;
	size_t	i;

	if (!base || !get_radix(&radix, base))
		return (NULL);
	len = ullitoa_len(num, radix) + sign;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (sign)
	{
		str[0] = '-';
		i++;
	}
	while (len > i)
	{
		str[len - 1] = base[num % radix];
		num /= radix;
		len--;
	}
	return (str);
}
