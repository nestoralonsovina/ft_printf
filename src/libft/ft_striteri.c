/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:50:47 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/06 16:50:48 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int n;

	n = 0;
	if (s && f)
	{
		while (*s)
		{
			f(n, &(*s));
			n++;
			s++;
		}
	}
}
