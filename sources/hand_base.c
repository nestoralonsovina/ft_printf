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
