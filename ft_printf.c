/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/12/01 15:14:17 by nalonso          ###   ########.fr       */
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
	done = res->len;
	free(res->buff);
	free(res);
	return (done);
}
