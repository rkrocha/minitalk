/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:02:12 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/23 09:18:25 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_flags(t_params *conv)
{
	if (conv->width < 0)
	{
		conv->width *= -1;
		conv->flag_minus = true;
	}
	if (conv->precision < 0)
	{
		conv->precision = 0;
		conv->flag_precision = false;
	}
	if (conv->flag_minus && conv->flag_zero)
		conv->flag_zero = false;
	if (conv->flag_zero && conv->flag_precision && conv->precision >= 0)
		if (!ft_strchr("cs%", conv->specifier))
			conv->flag_zero = false;
}

static char	*get_precision_value(t_params *conv, va_list ap, char *tracker)
{
	if (ft_isdigit(*tracker))
	{
		conv->precision = ft_atoi(tracker);
		tracker = ft_strignore(tracker, "0123456789");
		tracker = ft_strsearch(tracker, ".123456789*");
	}
	else if (*tracker == '*')
	{
		conv->precision = va_arg(ap, int);
		tracker++;
		tracker = ft_strsearch(tracker, ".123456789*");
	}
	else
		conv->precision = 0;
	return (tracker);
}

static void	get_width_precision(t_params *conv, va_list ap)
{
	char	*tracker;

	tracker = ft_strsearch(conv->string, ".123456789*");
	while (tracker && *tracker)
	{
		if (*tracker == '.')
			tracker = get_precision_value(conv, ap, tracker + 1);
		else if (ft_isdigit(*tracker))
		{
			conv->width = ft_atoi(tracker);
			tracker = ft_strignore(tracker, "0123456789");
			tracker = ft_strsearch(tracker, ".123456789*");
		}
		else if (*tracker == '*')
		{
			conv->width = va_arg(ap, int);
			tracker++;
			tracker = ft_strsearch(tracker, ".123456789*");
		}
		else
			break ;
	}
	adjust_flags(conv);
}

void	printf_get_flags(t_params *conv, va_list ap)
{
	char	*ptr;

	if (ft_strchr(conv->string, '.'))
		conv->flag_precision = true;
	if (ft_strchr(conv->string, '-'))
		conv->flag_minus = true;
	ptr = ft_strchr(conv->string, '0');
	while (ptr && !conv->flag_zero)
	{
		if (ptr == conv->string
			|| (*(ptr - 1) != '.' && !ft_isdigit(*(ptr - 1))))
			conv->flag_zero = true;
		ptr++;
		ptr = ft_strchr(ptr, '0');
	}
	get_width_precision(conv, ap);
}

bool	printf_copy_conv(char **start, t_params *conv)
{
	char	*end;

	(*start)++;
	end = ft_strsearch(*start, PRINTF_SPECIFIERS);
	if (end)
	{
		if (end == ft_strignore(*start, PRINTF_CONV_CHARS))
		{
			conv->string = ft_substr(*start, 0, end - *start + 1);
			conv->specifier = *end;
			*start = end + 1;
			if (conv->string)
				return (true);
		}
	}
	return (false);
}
