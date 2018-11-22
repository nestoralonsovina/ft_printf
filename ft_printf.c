/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/22 10:22:22 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

// pas tres bien fais
/*
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
*/
int		ft_printf(const char *format, ...)
{
	va_list arg;
	int		done;
	char	*stdesp;

	va_start(arg, format);
	stdesp = handle_args(format, arg);
	va_end(arg);
	ft_putstr(stdesp);
	return (ft_strlen(stdesp));
}
