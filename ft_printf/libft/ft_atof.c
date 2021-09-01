/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:02:11 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/10 09:34:35 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	treat_sign(const char **str, char *sign)
{
	*sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
		*sign = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
}

float	ft_atof(const char *str)
{
	float	number;
	char	fraction;
	char	sign;

	number = 0;
	fraction = 0;
	treat_sign(&str, &sign);
	while (ft_isdigit(*str))
	{
		number = number * 10.0 + (*str - '0');
		str++;
	}
	if (*str != '.')
		return (number * sign);
	str++;
	while (ft_isdigit(*str))
	{
		number = number * 10.0 + (*str - '0');
		fraction++;
		str++;
	}
	while (fraction--)
		number /= 10.0;
	return (number * sign);
}
