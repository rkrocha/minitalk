/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:16:26 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/23 09:08:13 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	branch_by_specifier(t_params *conv, va_list ap, int *nprint)
{
	if (conv->specifier == 'c')
		printf_char(*conv, ap, nprint);
	else if (conv->specifier == 's')
		printf_prep_str(conv, ap, nprint);
	else if (conv->specifier == 'p')
		printf_prep_ptr(conv, ap, nprint);
	else if (conv->specifier == 'd' || conv->specifier == 'i')
		printf_prep_int(conv, ap, nprint);
	else if (conv->specifier == 'u')
		printf_prep_int(conv, ap, nprint);
	else if (conv->specifier == 'x' || conv->specifier == 'X')
		printf_prep_hex(conv, ap, nprint);
	else if (conv->specifier == '%')
		printf_char(*conv, ap, nprint);
	return ;
}

static void	get_conversion(char **conversion, int *nprint, va_list ap)
{
	t_params	conv;

	ft_bzero(&conv, sizeof(conv));
	if (printf_copy_conv(conversion, &conv))
	{
		printf_get_flags(&conv, ap);
		ft_strdel(&(conv.string));
		branch_by_specifier(&conv, ap, nprint);
		return ;
	}
	*nprint = -1;
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*conversion;
	char	*print_marker;
	int		nprint;

	va_start(ap, format);
	nprint = 0;
	print_marker = (char *)format;
	while (nprint != -1)
	{
		conversion = ft_strchr(print_marker, '%');
		if (!conversion)
		{
			ft_putstr(print_marker);
			nprint += ft_strlen(print_marker);
			break ;
		}
		ft_putnstr(print_marker, conversion - print_marker);
		nprint += conversion - print_marker;
		get_conversion(&conversion, &nprint, ap);
		print_marker = conversion;
	}
	va_end(ap);
	return (nprint);
}
