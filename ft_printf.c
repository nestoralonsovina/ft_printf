/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/28 11:00:33 by nalonso          ###   ########.fr       */
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
	//printf("\n\n res len %d \n\n", res->len);
	ft_putstr(res->buff);
	done = res->len + ft_strlen(res->buff);
	//printf("return ft_strlen(res->buff) %lu\n", ft_strlen(res->buff));
	//printf(RED "stored on done %d\n" RESET, done);
	//printf("return res->len + ft_strlen(res->buff) %lu\n", res->len + ft_strlen(res->buff));
	free(res->buff);
	free(res);
	return (done);
}
