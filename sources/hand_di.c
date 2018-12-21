#include "../includes/ft_printf.h"

static int		is_negative(t_param *n)
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

static void      to_unsigned(t_param *n, int neg)
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


