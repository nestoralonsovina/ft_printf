/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:23:56 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/20 12:17:59 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <locale.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		handle_args(const char *format, va_list arg);
int     handle_conversions(char flags[], va_list al);


// FUNCTIONS TO HANDLE DIFFERENT FLAGS

int		handle_str(char *flags, char *str);
int		handle_char(char *flags, char c);
int		handle_ptr(char *flags, void *ptr);
int		handle_long(char *flags, va_list al);
int		handle_int(char *flags, va_list al);
int		handle_float(char *flags, va_list al);
int		handle_octal(char *flags, va_list al);
int		handle_decimal(char *flags, va_list al);
int		handle_hexa(char *flags, va_list al);
#endif
