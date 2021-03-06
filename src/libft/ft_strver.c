/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:01:57 by nalonso           #+#    #+#             */
/*   Updated: 2019/04/09 16:42:26 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strver(char *str, int (f)(int))
{
	while (*str)
	{
		if (f(*str) == 0)
			return (0);
		str += 1;
	}
	return (1);
}
