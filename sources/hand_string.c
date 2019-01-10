/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:23:37 by nalonso           #+#    #+#             */
/*   Updated: 2019/01/10 16:27:26 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
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
*/
void	handle_c(t_param *n, t_printf *head)
{
	char	*ind;

	ind = NULL;
	if (!(n->ind & NONE))
	{
		n->width -= 1;
		ind = add_ind(ft_strdup(""), n);
		if (n->ind & MINUS)
		{
			head->len += write(1, &n->data.c, 1);
			head->len += write(1, ind, ft_strlen(ind));
		}
		else
		{
			head->len += write(1, ind, ft_strlen(ind));
			head->len += write(1, &n->data.c, 1);
		}
	}
	else
		head->len += write(1, &n->data.c, 1);
	n->pf_string = NULL;
}

void	handle_str(t_param *n)
{
	char	*res;

	if (n->data.str == NULL)
		res = ft_strndup("(null)", n->ind & PRECISION ? n->precision : 6);
	else
		res = ft_strndup(n->data.str, n->ind & PRECISION ? \
				n->precision : (int)ft_strlen(n->data.str));
	if (!(n->ind & NONE))
		res = add_ind(res, n);
	n->pf_string = res;
}
