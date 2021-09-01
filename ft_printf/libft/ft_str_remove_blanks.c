/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_blanks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:47:07 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/19 12:06:32 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_remove_blanks(char *str)
{
	size_t	printer;
	size_t	reader;

	printer = 0;
	reader = 0;
	while (str[reader])
	{
		while (str[reader] && !ft_isspace(str[reader]))
		{
			str[printer] = str[reader];
			printer++;
			reader++;
		}
		while (str[reader] && ft_isspace(str[reader]))
			reader++;
		if (printer > 0 && str[reader] && !ft_isspace(str[reader]))
		{
			str[printer] = ' ';
			printer++;
		}
	}
	if (str[printer])
		str[printer] = '\0';
	return (str);
}
