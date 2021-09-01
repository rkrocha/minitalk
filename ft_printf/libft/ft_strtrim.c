/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:39:32 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 10:56:57 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(const char *set, char c)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && check_set(set, s1[i]))
		i++;
	start = (char *)&s1[i];
	i = ft_strlen(s1);
	if (i > 0)
		while (--i > 0 && check_set(set, s1[i]))
			;
	end = (char *)&s1[i];
	len = 0;
	while (start + len <= end)
		len++;
	return (ft_substr(start, 0, len));
}
