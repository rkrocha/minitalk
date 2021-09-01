/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:57:02 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/19 11:29:33 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char ***str_array)
{
	size_t	i;

	i = 0;
	while ((*str_array)[i])
	{
		ft_strdel(&((*str_array)[i]));
		i++;
	}
	free(*str_array);
	*str_array = NULL;
}
