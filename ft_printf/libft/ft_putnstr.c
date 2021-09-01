/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 03:58:25 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/11 04:05:56 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, size_t n)
{
	size_t	len;

	if (n == 0 || !str)
		return ;
	len = ft_strlen(str);
	if (n < len)
		len = n;
	write(1, str, len);
}
