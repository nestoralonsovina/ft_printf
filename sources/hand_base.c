#include "../includes/ft_printf.h"

static char	*ft_strupper(char *res)
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

void	handle_base(t_param *n, unsigned int base)
{
	char	*res;
	char	i[3];
	int		err;

	res = data_to_base(n, base);
	err = (!(ft_strcmp("0", res))) ? 1 : 0;
	n->width = ((n->precision > n->width) && (n->ind & ZERO)) ? n->precision : n->width;
	(base == 8 && ((n->ind & ZERO) && n->width <= (int)ft_strlen(res)) && n->ind & SHARP) ? n->ind &= ~ZERO : 0;
	if ((base == 8) && !(n->ind & ZERO) && (n->ind & SHARP))
		i[0] = '0';
	i[2] = '\0';
	if ((!err))
		res = fstrjoin(ft_strdup(i), res);
	if (((n->ind & PRECISION) && !(n->ind & ZERO) && (n->precision != 0)) || err)
		res = add_prec(res, n);
	res = add_ind(res, n);
	if (err && base == 8 && n->precision == 0)
		res = fstrjoin(ft_strdup(i), res);
	n->pf_string = res;
}

void	handle_hexa(t_param *n, unsigned int base)
{
	char *res;
	char i[3];
	int		nb;

	res = data_to_base(n, base);
	nb = ft_strcmp("0", res);
	(n->ind & ZERO && n->ind & MINUS) ? n->ind &= ~ZERO : 0;
	(n->ind & SHARP && n->ind & ZERO && nb) ? n->width -= 2 : 0;
	n->precision = (n->ind & ZERO && n->width > n->precision) ? \
				   n->width : n->precision;
	if (nb && (n->ind & SHARP) && (base == 16))
		i[0] = '0';
	if (nb && (n->ind & SHARP) && (base == 16))
		i[1] = 'x';
	i[2] = '\0';
	if (!(n->ind & PRECISION) && !( n->ind & ZERO))
		res = fstrjoin(ft_strdup(i), res);
	if (n->ind & PRECISION || n->ind & ZERO)
		res = add_prec(res, n);
	if (n->ind & PRECISION || n->ind & ZERO)
		res = fstrjoin(ft_strdup(i), res);
	res = add_ind(res, n);
	n->pf_string = (n->conv == BIGX) ? ft_strupper(res) : res;
}


void	handle_ptr(t_param *n)
{
	char	*res;

	if (n->precision == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base((unsigned long long)n->data.ptr, 16);
	if (n->ind & CLEAR && n->width > n->precision)
	{
		res = fstrjoin(ft_strdup("0x"), res);
		if (n->precision)
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
