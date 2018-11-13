/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:23:56 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/12 15:10:01 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <locale.h>

int		ft_printf(const char *format, ...);
int		handle_args(const char *format, va_list arg);


// FUNCTIONS TO HANDLE DIFFERENT FLAGS

int		handle_s(char *flags, char *str);
int		handle_c(char *flags, char c);
int		handle_p(char *flags, void *ptr);

#endif
