/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/12 15:19:59 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	print_hex(long nb)
{
	if (nb >= 16)
		print_hex(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar('a' + (nb % 16) - 10);
	else
		ft_putchar((nb % 16) + '0');
}

int		handle_s(char *flags, char *str)
{
	char	*ptr;

	ptr = str;
	if (*flags == 's')
	{
		if (*(flags + 1) == '\0')
		{
			if (str)
				while (*str)
					write(1, str++, 1);
		}
	}
	return (str - ptr);
}

int		handle_c(char *flags, char c)
{
	if (*flags == 'c' && c)
	{
		if (*(flags+ 1) == '\0')
			write(1, &c, 1);
	}
	else
		return (0);
	return (1);
}

int		handle_p(char *flags, void *pointer)
{
	int		hex;
	
	if (*flags == 'p')
	{
		if (*(flags + 1) == '\0')
		{
			write(1, "0x", 2);
			print_hex((long)pointer);
		}
	}
	return (123);
}

int		handle_args(const char *format, va_list al)
{

	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 's')
				handle_s("s", va_arg(al, char *));
			if (*format == 'c')
				handle_c("c", (char)va_arg(al, int));
			if (*format == 'p')
				handle_p("p", va_arg(al, void *));
		}
		else
			ft_putchar(*format);
		format++;
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
