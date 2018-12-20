/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:55:39 by nalonso           #+#    #+#             */
/*   Updated: 2018/12/20 12:07:17 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(t_param *n, t_printf *head)
{
	char	*res;

	res = NULL;
	if (n->data.c == 0)
	{
		if (n->ind & CLEAR || n->ind & ZERO)
		{
			--n->width;
			res = add_ind(ft_strdup(""), n);
			head->len += write(1, res, ft_strlen(res));
			free(res);
		}
		head->len += write(1, &n->data.c, 1);
	}
	else
	{
		res = ft_strdup(" ");
		res[0] = n->data.c;
		n->precision = -1;
		res = add_ind(res, n);
		n->pf_string = res;
		head->len += write(1, n->pf_string, ft_strlen(n->pf_string));
		free(res);
	}
	n->pf_string = NULL;
}

void	handle_str(t_param *n)
{
	char	*res;

	if (n->data.str == NULL)
		res = ft_strndup("(null)", n->ind & PRECISION ? n->precision : 6);
	else
		res = ft_strndup(n->data.str, n->ind & PRECISION ? \
				n->precision : ft_strlen(n->data.str));
	if (!(n->ind & NONE))
		res = add_ind(res, n);
	n->pf_string = res;
}

void	handle_ptr(t_param *n)
{
	char	*res;

	res = ft_itoa_base((unsigned long long)n->data.ptr, 16);
	if (n->precision == 0)
	{
		free(res);
		res = ft_strdup("");
	}
	if (n->ind & CLEAR && n->width > n->precision)
	{
		res = fstrjoin(ft_strdup("0x"), res);
		res = add_prec(res, n);
		res = add_ind(res, n);
	}
	else
	{
		n->width -= 2;
		res = add_prec(res, n);
		res = add_ind(res, n);
		res = fstrjoin(ft_strdup("0x"), res);
	}
	n->pf_string = res;
}

int		is_negative(t_param *n)
{
	if (n->data.i < 0 && (n->mod == NO))
		return (-1);
	else if (n->data.l < 0 && n->mod == L)
		return (-1);
	else if (n->data.ll < 0 && n->mod == LL)
		return (-1);
	else if (n->data.s < 0 && n->mod == H)
		return (-1);
	else if (n->data.sc < 0 && n->mod == HH)
		return (-1);
	return (1);
}

void	to_unsigned(t_param *n, int neg)
{
	if (n->mod == NO)
		n->data.ui = neg * n->data.i;
	else if (n->mod == L)
		n->data.ul = neg * n->data.l;
	else if (n->mod == LL)
		n->data.ull = neg * n->data.ll;
	else if (n->mod == H)
		n->data.us = neg * n->data.s;
	else if (n->mod == HH)
		n->data.uc = neg * n->data.sc;
}

void	handle_integer(t_param *n)
{
	char	*res;
	int		neg;

	neg = is_negative(n);
	to_unsigned(n, neg);
	neg = (neg < 0) ? 1 : 0;
	res = data_to_base(n, 10);
	(n->precision > n->width) ? n->width = n->precision : 0;
	if (n->ind & PRECISION)
	{
		if (ft_strcmp("0", res) == 0)
		{
			res = ft_strdup("");
			res = add_prec(res, n);
		}
		else if (n->precision)
			res = add_prec(res, n);
	}
	if ((neg || n->ind & PLUS || n->ind & SPACE) && (n->ind & ZERO))
	{
		--n->width;
		res = add_ind(res, n);
		res = fstrjoin(ft_strdup(" "), res);
		(n->ind & SPACE) ? res[0] = ' ' : 0;
		(neg) ? res[0] = '-' : 0;
		(n->ind & PLUS && !neg) ? res[0] = '+' : 0;
	}
	else if (neg || n->ind & PLUS || n->ind & SPACE)
	{
		res = fstrjoin(ft_strdup(" "), res);
		(n->ind & SPACE) ? res[0] = ' ' : 0;
		(neg) ? res[0] = '-' : 0;
		(n->ind & PLUS && !neg) ? res[0] = '+' : 0;
		res = add_ind(res, n);
	}
	else
	{
		res = add_ind(res, n);
	}
	n->pf_string = res;

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

void	handle_base(t_param *n, unsigned int base)
{
	char	*res;
	char	i[3];
	int		err;

	res = data_to_base(n, base);
	err = (!(ft_strcmp("0", res))) ? 1 : 0;
	n->width = ((n->precision > n->width) && (n->ind & ZERO)) ? n->precision : n->width;
	(base == 16 && (n->ind & ZERO) && (n->ind & SHARP) && !(n->ind & MINUS)) ? n->width -= 2 : 0;
	if (((base == 8 || base == 16) && !(base == 8 && n->ind & ZERO) && (n->ind & SHARP)) || n->conv == P)
		i[0] = '0';
	if (n->conv == P || (base == 16 && n->ind & SHARP))
		i[1] = n->conv == BIGX ? 'X' : 'x';
	i[2] = '\0';
	if ((!err && !(base == 16 && (n->ind & ZERO) && !(n->ind & MINUS))) || (n->conv == P && !(n->ind & ZERO)))
		res = fstrjoin(ft_strdup(i), res);
	if (((n->ind & PRECISION) && !(n->ind & ZERO) && (n->precision != 0)) || err)
		res = add_prec(res, n);
	res = add_ind(res, n);
	if ((err && base == 8 && (n->ind & PRECISION)) || (base == 16 && (n->ind & ZERO) && !(n->ind & MINUS)))
		res = fstrjoin(ft_strdup(i), res);
	n->pf_string = (n->conv == BIGX) ? ft_strupper(res) : res;
}


/*
	if ((n->width > 0 || n->ind & PLUS) && n->ind & SPACE)
		n->ind &= ~SPACE;
	if (n->precision != 0 || ft_strcmp(res, "0") == 0)
	{
		res = add_prec(res, n);
	}
	if (neg == -1 && !(n->ind & CLEAR) && !(n->ind & ZERO))
		res = fstrjoin(ft_strdup("-"), res);
	else if (n->ind & PLUS && neg > -1 && n->ind & NONE)
		res = fstrjoin(ft_strdup("+"), res);
	else
	{
		if (n->ind & ZERO)
		{
			if (neg == -1)
				--(n->width);
			else if (n->ind & PLUS)
				--(n->width);
			res = add_ind(res, n);
			if (neg == -1)
				res = fstrjoin(ft_strdup("-"), res);
			else if (n->ind & PLUS)
				res = fstrjoin(ft_strdup("+"), res);
		}
		else if (n->ind & CLEAR)
		{
			if (neg == -1)
				res = fstrjoin(ft_strdup("-"), res);
			else if (n->ind & PLUS)
				res = fstrjoin(ft_strdup("+"), res);
			res = add_ind(res, n);
		}
	}
	if (n->ind & SPACE && neg > -1)
		n->pf_string = fstrjoin(ft_strdup(" "), res);
	else
		n->pf_string = res;
*/
char	*data_to_base(t_param *n, int base)
{
	char	*res;

	if (n->mod == H)
		res = ft_itoa_base(n->data.us, base);
	else if (n->mod == HH)
		res = ft_itoa_base(n->data.uc, base);
	else if (n->mod == L)
		res = ft_itoa_base(n->data.ul, base);
	else if (n->mod == LL)
		res = ft_itoa_base(n->data.ull, base);
	else
		res = ft_itoa_base(n->data.ui, base);
	return (res);
}
