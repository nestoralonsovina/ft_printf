/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:28 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/12 14:14:31 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *name = "Nestor";
	char *surname = "Alonso";

	ft_putendl("Test %s flag:");
	ft_printf("ft_printf - string: %s", name);
	printf("printf - string: %s\n", name);
	ft_putendl("------------------------------------");
	ft_putendl("Test %p flag:");
	ft_printf("ft_printf - address: %p ", name);
	printf("printf - address: %p\n", name);
	ft_printf("ft_printf - address: %p ", surname);
	printf("printf - address: %p\n", surname);
	ft_putendl("------------------------------------");
}
