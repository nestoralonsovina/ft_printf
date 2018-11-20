/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/20 15:07:57 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		is_conversion(char c)
{
	char flags[] = "cspfdiouxX";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

int		handle_conversions(char flags[], va_list al)
{
	int ret;
	
	ret = 0;
	if (ft_strchr(flags, 's'))
		ret += handle_str(flags, va_arg(al, char *));
	else if (ft_strchr(flags, 'p'))
		ret += handle_ptr(flags, va_arg(al, void *));
	else if (ft_strchr(flags, 'c'))
		ret += handle_char(flags, (char)va_arg(al, int));
	else if (ft_strchr(flags, 'l'))
		ret += handle_long(flags, al);
	else if (ft_strchr(flags, 'd') || ft_strchr(flags, 'i'))
		ret += handle_int(flags, al);
	else if (ft_strchr(flags, 'f'))
		ret += handle_float(flags, al);
	else if (ft_strchr(flags, 'o'))
		ret += handle_octal(flags, al);
	else if (ft_strchr(flags, 'u'))
		ret += handle_decimal(flags, al);
	else if (ft_strchr(flags, 'x') || ft_strchr(flags, 'X'))
		ret += handle_hexa(flags, al);
	return (ret);
}

int		handle_args(const char *format, va_list al)
{
	char	flags[12];
	int		i;
	int		ret;
	
	ft_bzero(flags, 12);
	i = 0;
	ret = 0;
	while (*format)
	{
		if (*format == '%' && *(++format) != '%') // posible seg fault if i try to access uninitialize memory
		{
			// format += 1;  // shouldn't be necessary now
			while (!is_conversion(*format) && *format)
			{
				flags[i++] = *format++;
			}
			flags[i] = *format;
			i = 0;
			// printf("%s\n", flags);  // debug stored flags
			ret += handle_conversions(flags, al);
		}
		else
			ret += write(1, format, 1);
		format += 1;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int		done;

	va_start(arg, format);
	done = handle_args(format, arg);
	va_end(arg);
	return (done);
}
