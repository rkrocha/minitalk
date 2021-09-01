/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:16:53 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:22:55 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	unsigned char			chr;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	chr = (unsigned char)c;
	while (n)
	{
		if (*s == chr)
		{
			*d = *s;
			return (++d);
		}
		*d++ = *s++;
		n--;
	}
	return (NULL);
}
