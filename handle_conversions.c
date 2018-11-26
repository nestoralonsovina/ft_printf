/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:39 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/26 17:35:05 by nalonso          ###   ########.fr       */
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
			if (node->ind == CLEAR || node->conv == S || node->conv == P || node->conv == C || ft_strchr(node->flags, '-'))
				new = add_char(new, ' ');
			else
				new = add_char(new, '0');
			--(node->width);
		}
		if (ft_strchr(node->flags, '-'))
			new = fstrjoin(str, new);
		else
			new = fstrjoin(new, str);
		return (new);
	}
}

void	handle_str(t_param *node)
{
	char	*res;
	if (node->data.str == NULL)
	{
		res = ft_strdup("(null)");
		handle_ind(res, node);
		return ;
	}
	else
		res = ft_strdup(node->data.str);
	if (ft_strchr(node->flags, '.') && (size_t)node->precision < ft_strlen(res))
		res[node->precision] = '\0';
	handle_ind(res, node);
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

int		is_negative(t_param *node)
{
	if (node->data.i < 0 && (node->mod == NO))
		return (-1);
	else if (node->data.l < 0 && node->mod == L)
		return (-1);
	else if (node->data.ll < 0 && node->mod == LL)
		return (-1);
	else if (node->data.s < 0 && node->mod == H)
		return (-1);
	else if (node->data.sc < 0 && node->mod == HH)
		return (-1);
	return (1);
}

void	to_unsigned(t_param *node, int neg)
{
	if (node->mod == NO)
		node->data.ui = neg * node->data.i;
	else if (node->mod == L)
		node->data.ul = neg * node->data.l;
	else if (node->mod == LL)
		node->data.ull = neg * node->data.ll;
	else if (node->mod == H)
		node->data.us = neg * node->data.s;
	else if (node->mod == HH)
		node->data.uc = neg * node->data.sc;
}

void	handle_u(t_param *node)
{
	char *res;

	res = data_to_base(node, 10);
	if (node->ind == NONE)
		node->pf_string = res;
	else
		node->pf_string = add_ind(res, node);
}

void	handle_integer(t_param *node)
{
	char	*res;
	int		negative;

	//negative = 0;
	negative = is_negative(node);
	to_unsigned(node, negative);
	res = data_to_base(node, 10);
	if (negative == -1)
		res = fstrjoin(ft_strdup("-"), res);
	if (node->ind == NONE)
		node->pf_string = res;
	else
		node->pf_string = add_ind(res, node);
}

char	*data_to_base(t_param *node, int base)
{
	char	*res;

	if (node->mod == H)
		res = ft_itoa_base(node->data.us, base);
	else if (node->mod == HH)
		res = ft_itoa_base(node->data.uc, base);
	else if (node->mod == L)
		res = ft_itoa_base(node->data.ul, base);
	else if (node->mod == LL)
		res = ft_itoa_base(node->data.ull, base);
	else
		res = ft_itoa_base(node->data.ui, base);
	return (res);
}

void	handle_octal(t_param *node)
{
	char	*res;

	res = data_to_base(node, 8);
	if (node->ind == NONE)
		node->pf_string = res;
	else
		node->pf_string = add_ind(res, node);
}

char	*ft_strupper(char *res)
{
	char	*ptr;

	ptr = res;
	while (*res)
	{
		*res = ft_toupper(*res);
		++res;
	}
	return (ptr);
}

void	handle_ind(char *res, t_param *node)
{
	if (node->ind == NONE)
		node->pf_string = res;
	else
		node->pf_string = add_ind(res, node);
}

void	handle_hexa(t_param *node)
{
	char	*res;

	res = data_to_base(node, 16);
	if (ft_strcmp(res, "0") == 0)
	{
		node->pf_string = res;
		return ;
	}
	if (ft_strchr(node->flags, '#'))
	{
		if (node->ind < ZERO)
		{
			res = fstrjoin(ft_strdup("0x"), res);
			handle_ind(res, node);
		}
		else if (node->ind == ZERO)
		{
			node->width -= 2;
			handle_ind(res, node);
			node->pf_string = fstrjoin(ft_strdup("0x"), node->pf_string);
		}
	}
	else
		handle_ind(res, node);
	if (node->conv == BIGX)
		node->pf_string = ft_strupper(node->pf_string);
}
