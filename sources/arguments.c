#include "../includes/ft_printf.h"

void		set_conversion(char con, t_param *curr)
{
	if (con == 's')
		curr->conv = S;
	else if (con == 'c')
		curr->conv = C;
	else if (con == 'p')
		curr->conv = P;
	else if (con == 'd' || con == 'D')
		curr->conv = D;
	else if (con == 'i')
		curr->conv = I;
	else if (con == 'f' || con == 'F')
		curr->conv = F;
	else if (con == 'o' || con == 'O')
		curr->conv = O;
	else if (con == 'u' || con == 'U')
		curr->conv = U;
	else if (con == 'x')
		curr->conv = X;
	else if (con == 'X')
		curr->conv = BIGX;
	else if (con == 'b')
		curr->conv = B;
	else
		curr->conv = NON;
}

void		search_arg(t_param *new, va_list al)
{
	if (new->conv == P)
		new->data.ptr = va_arg(al, void *);
	else if (new->conv == S)
		new->data.str = va_arg(al, char *);
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
	{
		if (new->mod == BIGL)
			new->data.ld = va_arg(al, long double);
		else
			new->data.d = va_arg(al, double);
	}
}

void convert_arg(t_printf *p)
{
	if (p->curr->conv == S)
		handle_str(p->curr);
	else if (p->curr->conv == P)
		handle_ptr(p->curr);
	else if (p->curr->conv == D || p->curr->conv == I)
		handle_integer(p->curr);
	else if (p->curr->conv == O)
		handle_base(p->curr, 8);
	else if (p->curr->conv == X || p->curr->conv == BIGX)
		handle_base(p->curr, 16);
	else if (p->curr->conv == U)
		handle_base(p->curr, 10);
	else if (p->curr->conv == C)
		handle_c(p->curr, p);
	else if (p->curr->conv == F)
		handle_float(p->curr);
	else if (p->curr->conv == B)
		handle_base(p->curr, 2);
}

void	search_width_precision(t_printf *p)
{
	if (ft_isdigit(*p->inp))
	{
		p->curr->width = ft_atoi(p->inp);
		while (ft_isdigit(*p->inp))
			++p->inp;
	}
	if (*p->inp == '.')
	{
		++p->inp;
		p->curr->precision = ft_atoi(p->inp) > 0 ? ft_atoi(p->inp) : 0;
		while (ft_isdigit(*p->inp))
			++p->inp;
		p->curr->ind |= PRECISION;
	}
}

void	assign_flag(t_printf *p)
{
	t_param	*a;

	a = p->curr;
	if (*p->inp == '#')
		a->ind |= SHARP;
	else if (*p->inp == '+')
		a->ind |= PLUS;
	else if (*p->inp == '-')
		a->ind |= MINUS;
	else if (*p->inp == ' ')
		a->ind |= SPACE;
	else if (*p->inp == '0')
		a->ind |= ZERO;
}

void parse_arg(t_printf *p, va_list al)
{
	t_param	*a;

	p->curr = (t_param *)malloc_safe(sizeof(t_param));
	a = p->curr;
	a->ind = 0;
	a->width = 0;
	a->precision = 1;
	while (ft_strchr("#+- 0", *p->inp))
		{assign_flag(p);++p->inp;}
	search_width_precision(p);
	if (a->width > 0 && !(a->ind & ZERO))
		{a->ind |= CLEAR;}
	if (!(a->ind & CLEAR) && !(a->ind & ZERO))
		a->ind |= NONE;
	a->mod = NO;
	while (69)
	{
		if (*p->inp == 'l')
			a->mod = (p->inp[1] == 'l' && ++p->inp) ? LL : L;
		else if (*p->inp == 'h')
			a->mod = (p->inp[1] == 'h' && ++p->inp) ? HH : H;
		else if (*p->inp == 'L')
			a->mod = BIGL;
		else
			break ;
		++p->inp;
	}
	if (*p->inp == '%')
		a->pf_string = add_ind(ft_strdup("%"), a);
	else if (*p->inp == 'n')
		*(va_arg(al, int *)) = p->len;
	else if (ft_strchr("bcspdiouxXfFODU", *p->inp) == NULL || !*p->inp)
	{
		if (*p->inp)
			p->len += write(1, p->inp, 1);
		a->pf_string = NULL;
	}
	else if (*p->inp)
	{
		if (ft_strchr("ODU", *p->inp) != NULL)
			a->mod = a->mod == L ? LL : L;
		set_conversion(*p->inp, p->curr);
		search_arg(p->curr, al);
		convert_arg(p);
	}
}

t_printf *handle_args(const char *format, va_list al)
{
	t_printf	*p;

	p = (t_printf *)malloc_safe(sizeof(*p));
	p->inp = format;
	p->len = 0;
	while (*p->inp)
	{
		if (*p->inp == '%')
		{
			++p->inp;
			if (!*p->inp)
				break;
			parse_arg(p, al);
			if (p->curr->pf_string)
			{
				p->len += write(1, p->curr->pf_string, ft_strlen(p->curr->pf_string));
				free(p->curr->pf_string);
				free(p->curr);
			}
		}
		else
		{
			if (!colors(p))
				p->len += write(1, p->inp, 1);
		}
		if (*p->inp)
			++p->inp;
	}
	return (p);
}
