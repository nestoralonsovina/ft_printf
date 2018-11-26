/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/26 11:04:00 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int		done;
	char	*stdesp;

	va_start(arg, format);
	stdesp = handle_args(format, arg);
	va_end(arg);
	ft_putstr(stdesp);
	done = ft_strlen(stdesp);
	free(stdesp);
	return (done);
}
