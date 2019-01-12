/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:13:23 by nalonso           #+#    #+#             */
/*   Updated: 2019/01/11 14:31:27 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static double	ft_dabs(double n)
{
	return (n < 0 ? -n : n);
}

static double	ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

/*
 *(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
 	(p->f & F_SPACE) ? s[0] = ' ' : 0;
		(n < 0) ? s[0] = '-' : 0;
		(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
 *
 * */
/*
void			float_indentation(char *res, t_param *a, long double n)
{

}
*/

void			dtoa_string(long double n, t_param *a, long value, t_printf *p)
{
	int		len;
	char	s[256];
	char	*buff;
	long	tmp;
	
	ft_bzero(s, 256);
	buff = NULL;
	len = 0;
	tmp = (long)(n > 0 ? n : -n);
	(n < 0.0) ? s[len++] = '-' : 0;
	ft_strcat(s, ft_itoa_base(tmp, 10));
	len = ft_strlen(s);
	s[len++] = '.';
	s[len] = '\0';
	len += a->precision;
	buff = ft_itoa_base(value, 10);
	if (a->precision > (int)ft_strlen(buff))
		buff = fstrjoin(buff, new_str('0', a->precision - ft_strlen(buff)));
	ft_strcat(s, buff);
	free(buff);
	s[len] = '\0';
	buff = add_ind(ft_strdup(s), a);
	buffer(p, buff, ft_strlen(buff));
	free(buff);
}

void			handle_float(t_param *a, t_printf *p)
{

	long double			n;
	long double			decimal;
	long long			value;

	n = (a->mod == BIGL) ? a->data.ld : a->data.d;
	value = 0;
	if (!(a->ind & PRECISION))
		a->precision = 6;
	decimal = ft_dabs(a->data.d);
	decimal = (decimal - (long long)(ft_dabs(n))) * ft_pow(10, a->precision + 1);
	decimal = ((long long)decimal % 10 > 4) ? decimal / 10 + 1 : decimal / 10;
	value = (long long)decimal;
	dtoa_string(n, a, value, p);
}

