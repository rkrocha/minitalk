/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:10:32 by rkochhan          #+#    #+#             */
/*   Updated: 2020/02/02 15:22:06 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1cmp;
	const unsigned char	*s2cmp;

	s1cmp = s1;
	s2cmp = s2;
	if (n == 0)
		return (0);
	while (--n && *s1cmp == *s2cmp)
	{
		s1cmp++;
		s2cmp++;
	}
	return (*s1cmp - *s2cmp);
}
