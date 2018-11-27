/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/27 16:40:10 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			done;
	t_printf	*res;

	va_start(arg, format);
	res = handle_args(format, arg);
	va_end(arg);
	ft_putstr(res->buff);
	res->len += ft_strlen(res->buff);
	free(res->buff);
	done = res->len;
	free(res);
	return (done);
}
