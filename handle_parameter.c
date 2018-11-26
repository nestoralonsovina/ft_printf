/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:09:50 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/26 16:19:51 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ret_conversion(char *flags, t_param *curr)
{
	char	posibles[] = "cspfdiouxX";
	char	con;
	int		i;

	i = 0;
	con = 0;
	while (posibles[i])
	{
		if (ft_strchr(flags, posibles[i]) != NULL)
			con = posibles[i];
		++i;
	}
	if (con == 0)
		curr->conv = NON;
	else if (con == 's')
		curr->conv = S;
	else if (con == 'c')
		curr->conv = C;
	else if (con == 'p')
		curr->conv = P;
	else if (con == 'd')
		curr->conv = D;
	else if (con == 'i')
		curr->conv = I;
	else if (con == 'f')
		curr->conv = F;
	else if (con == 'o')
		curr->conv = O;
	else if (con == 'u')
		curr->conv = U;
	else if (con == 'x')
		curr->conv = X;
	else if (con == 'X')
		curr->conv = BIGX;
	return (con);
}

void	search_width(t_param *new)
{
	int i;
	i = 0;
	new->width = 0;
	if (new->flags[i] == '#')
		++i;
	if (new->flags[i] == '-')
	{
		++i;
	}
	if (new->flags[i] == '0')
	{
		++i;
		new->ind = ZERO;
	}else if (ft_isdigit(new->flags[i]))
		new->ind = CLEAR;
	else
		new->ind = NONE;
	while (ft_isdigit(new->flags[i]))
	{
		new->width = new->width * 10 + new->flags[i] - '0';
		++i;
	}
}

void		search_precision(t_param *new)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strchr(new->flags, '.');
	new->precision = 0;
	if (ptr && ptr[i] == '.')
	{
		++i;
		while (ft_isdigit(ptr[i]))
		{
			new->precision = new->precision * 10 + ptr[i] - '0';
			++i;
		}
	}
}

void		search_modifier(t_param *new)
{
	char	*ptr;

	ptr = new->flags;
	if (ft_strstr(ptr, "ll"))
		new->mod = LL;
	else if (ft_strstr(ptr, "hh"))
		new->mod = HH;
	else if (ft_strstr(ptr, "l"))
		new->mod = L;
	else if (ft_strstr(ptr, "h"))
		new->mod = H;
	else if (ft_strstr(ptr, "L"))
		new->mod = BIGL;
	else
		new->mod = NO;
}

void		search_arg(t_param *new, va_list al)
{
	if (new->conv == P)
		new->data.ptr = va_arg(al, void *);
	else if (new->conv == S)
		new->data.ptr = va_arg(al, char *);
	else if (new->conv == C)
		new->data.c = va_arg(al, int);
	else if (new->conv == D || new->conv == I)
	{
		if (new->mod == H)
			new->data.s = va_arg(al, int);
		else if (new->mod == HH)
			new->data.sc = va_arg(al, int);
		else if (new->mod == L)
			new->data.l = va_arg(al, long);
		else if (new->mod == LL)
			new->data.ll = va_arg(al, long long);
		else
			new->data.i = va_arg(al, int);
	}
	else if (new->conv > I && new->conv < F)
	{
		if (new->mod == H)
			new->data.us = va_arg(al, int);
		else if (new->mod == HH)
			new->data.uc = va_arg(al, int);
		else if (new->mod == L)
			new->data.ul = va_arg(al, unsigned long);
		else if (new->mod == LL)
			new->data.ull = va_arg(al, unsigned long long);
		else
			new->data.ui = va_arg(al, unsigned int);
	}
	else if (new->conv == F)
		new->data.f = va_arg(al, double);
}

t_param		*init_param(char *flags, va_list al)
{
	t_param		*new;

	new = (t_param *)malloc_safe(sizeof(*new));
	new->conversion = ret_conversion(flags, new);
	new->flags = flags;
	search_width(new);
	search_precision(new);
	search_modifier(new);
	search_arg(new, al);
	//print_full_param(*new);
	return (new);
}
