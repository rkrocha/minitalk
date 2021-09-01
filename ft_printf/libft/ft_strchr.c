/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:25:39 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:55:39 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	if (!str)
		return (NULL);
	ptr = (char *)str;
	while (*ptr != c)
	{
		if (!*ptr)
			return (NULL);
		ptr++;
	}
	return (ptr);
}
