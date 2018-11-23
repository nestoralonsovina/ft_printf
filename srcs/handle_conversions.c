/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:39 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/23 11:42:30 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_ind(char *str, t_param *node)
{
	int		len;
	char	*new;

	str = ft_strdup(str);
	len = ft_strlen(str);
	new = ft_strnew(1);
	if (len >= node->width)
		return (str);
	else
	{
		while (node->width - len > 0)
		{
			if (node->ind == CLEAR || node->conv == S || node->conv == P)
				new = add_char(new, ' ');
			else
				new = add_char(new, '0');
			--(node->width);
		}
		new = fstrjoin(new, str);
		return (new);
	}
}

void	handle_str(t_param *node)
{
	if (node->ind == NONE)
		node->pf_string = ft_strdup((node->data).str);
	else
		node->pf_string = add_ind((node->data).str, node);
}

void	handle_ptr(t_param *node)
{
	char	*res;

	res = ft_itoa_base((unsigned int)node->data.ptr, 16);
	res = fstrjoin(ft_strdup("0x"), res);
	if (node->ind == NONE)
		node->pf_string = res;
	else
		node->pf_string = add_ind(res, node);
}

void	handle_integer(t_param *node)
{
	char	*res;
	
	if (node->mod == H)
		res = ft_itoa(node->data.s);
	else if (node->mod == HH)
		res = ft_itoa(node->data.sc);	
	else if (node->mod == L)
		res = ft_itoa(node->data.l);
	else if (node->mod == LL)
		res = ft_itoa(node->data.ll);
	else
		res = ft_itoa(node->data.i);
	if (node->ind == NONE)
		node->pf_string = res;
	else
		node->pf_string = add_ind(res, node);
}

void	handle_octal(t_param *node)
{
	char	*res;
	
	if (node->mod == H)
		res = ft_itoa_base(node->data.us, 8);
	else if (node->mod == HH)
		res = ft_itoa_base(node->data.uc, 8);	
	else if (node->mod == L)
		res = ft_itoa_base(node->data.ul, 8);
	else if (node->mod == LL)
		res = ft_itoa_base(node->data.ull, 8);
	else
		res = ft_itoa_base((unsigned int)node->data.i, 8);
	if (node->ind == NONE)
		node->pf_string = res;
	else
		node->pf_string = add_ind(res, node);	
}

