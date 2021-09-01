/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:48:23 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:21:56 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	dstlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	j = dstlen;
	while (src[i] != '\0' && j != size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dstlen + srclen);
}
