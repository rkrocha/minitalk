/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:44 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/23 09:21:52 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_char(t_params conv, va_list ap, int *nprint)
{
	int	c;

	if (conv.specifier == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (!conv.flag_minus && !conv.flag_zero && conv.width > 1)
		printf_putchar(' ', conv.width - 1, nprint);
	else if (conv.flag_zero && conv.width > 1)
		printf_putchar('0', conv.width - 1, nprint);
	printf_putchar(c, 1, nprint);
	if (conv.flag_minus && conv.width > 1)
		printf_putchar(' ', conv.width - 1, nprint);
}

void	printf_prep_str(t_params *conv, va_list ap, int *nprint)
{
	char	*temp;

	temp = va_arg(ap, char *);
	if (temp == NULL && conv->flag_precision)
		conv->string = ft_substr("(null)", 0, conv->precision);
	else if (temp == NULL)
		conv->string = ft_strdup("(null)");
	else if (conv->flag_precision)
		conv->string = ft_substr(temp, 0, conv->precision);
	else
		conv->string = ft_strdup(temp);
	(*conv).precision = 0;
	if (conv->string)
	{
		(*conv).len = ft_strlen(conv->string);
		printf_print(*conv, nprint, false, false);
	}
	else
		*nprint = -1;
	ft_strdel(&conv->string);
}
