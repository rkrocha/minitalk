/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:28:24 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/07 14:04:28 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static size_t	split_strlen(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static size_t	count_strs(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static bool	alloc_array(char ***array, size_t str_count, size_t elem_size)
{
	*array = (char **)malloc((str_count + 1) * elem_size);
	if (!(*array))
		return (false);
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	index;
	size_t	len;
	size_t	i;

	if (!s || !alloc_array(&strs, count_strs(s, c), sizeof(char *)))
		return (NULL);
	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		len = split_strlen(&s[i], c);
		strs[index] = ft_substr(&s[i], 0, len);
		if (!strs[index])
			return (free_all(strs));
		i += len;
		index++;
	}
	strs[index] = NULL;
	return (strs);
}
