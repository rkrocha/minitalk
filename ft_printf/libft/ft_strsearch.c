/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:03:40 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/14 13:48:51 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsearch(const char *str, const char *set)
{
	size_t		i;
	size_t		j;

	if (!str || !set)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (set[j])
		{
			if (str[i] == set[j])
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
