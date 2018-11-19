/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/19 17:38:46 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

/*
	pseudocode for handle_args:

	while (*format)
	{
		if (*format == '%')
		{
			while (*format is not equal to a valid conversion)
			{
				flags += format
				++formats;
			}
			depending on last *format value:
				call correspondant handler with flags and argument;
		}
	}
*/

int		is_conversion(char c)
{
	char flags[] = "cspfdiouxX";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

void	handle_conversions(char flags[], va_list al)
{
	if (ft_strchr(flags, 's'))
		handle_str(flags, va_arg(al, char *));
	if (ft_strchr(flags, 'p'))
		handle_ptr(flags, va_arg(al, void *));
	if (ft_strchr(flags, 'c'))
		handle_char(flags, (char)va_arg(al, int));	
}

int		handle_args(const char *format, va_list al)
{
	char	flags[12];
	int		i;
	
	ft_bzero(flags, 12);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			while (!is_conversion(*format) && *format)
			{
				flags[i++] = *format++;
			}
			flags[i] = *format;
			handle_conversions(flags, al);

			
		}
		else
			ft_putchar(*format);
		format += 1;
	}
	return (1);
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
