#include "ft_printf.h"

static double	ft_dabs(double n)
{
	return (n < 0 ? -n : n);
}

static double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

void			dtoa_string(double n, t_param *a, long value)
{
	int		len;
	char	s[256];
	long	tmp;

	len = 0;
	tmp = (long)(n > 0 ? n : -n);
	(n < 0) ? s[len++] = '-' : 0;
	ft_strcat(s, ft_itoa_base(tmp, 10));
	len = ft_strlen(s);
	s[len++] = '.';
	s[len] = '\0';
	len += a->precision;
	ft_strcat(s, ft_itoa_base(value, 10));
	s[len] = '\0';
	a->pf_string = ft_strdup(s);
}

void			handle_float(t_param *a)
{

	double		n;
	int			len;
	double		decimal;
	long		value;

	n = a->data.d;
	value = 0;
	if (!(a->ind & PRECISION))
		a->precision = 6;
	len = 1;
	decimal = ft_dabs(a->data.d); // valor absoluto for ever
	decimal = (decimal - (long)(ft_dabs(n))) * ft_pow(10, a->precision + 1); // primero se queda el 0.... y luego se coge el resto.
	decimal = ((long)decimal % 10 > 4) ? decimal / 10 + 1 : decimal / 10; // redondear el ultimo decimal para evita .1999999 o cosas asi
	value = (long)decimal;
	dtoa_string(n, a, value);
}

