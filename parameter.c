/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:09:50 by nalonso           #+#    #+#             */
/*   Updated: 2018/12/11 18:18:37 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
t_param		*init_param(char *flags, va_list al)
{
	t_param		*new;

	new = (t_param *)malloc_safe(sizeof(*new));
	new->conversion = ret_conversion(flags, new);
	if (ft_strcmp(flags, " d") != 0)
		new->flags = ft_strtrim(flags);
	else
		new->flags = ft_strdup(flags);
	search_width(new);
	search_precision(new);
	search_modifier(new);
	search_arg(new, al);
	return (new);
}*/
