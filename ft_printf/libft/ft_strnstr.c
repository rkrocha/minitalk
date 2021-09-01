/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:18:23 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:59:56 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	j = 0;
	while (haystack[i] && i <= len)
	{
		while (haystack[i + j] == needle[j] && len > (i + j))
		{
			if (j == needle_len - 1)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
