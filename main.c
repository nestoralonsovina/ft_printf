/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:28 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/20 12:17:01 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		main(void)
{
	char *name = "Nestor";
	char *surname = "Alonso";
	
	//printf("Flags test: "); ft_printf("%#10d");
	
	printf("test return : %d\n", printf("%s", name) == ft_printf("%s", name));
	
	
	ft_putendl("\nTest %%s flag:");
	ft_printf("ft_printf - string: %s %s\n", name, surname);
	printf("printf - string: %s\n", name);
	ft_putendl("------------------------------------");
	ft_putendl("Test %p flag:");
	ft_printf("ft_printf - address: %p\n", name);
	printf("printf - address: %p\n", name);
	ft_printf("ft_printf - address: %p\n", surname);
	printf("printf - address: %p\n", surname);
	ft_putendl("------------------------------------");
	ft_putendl("Test %c flag:");
	ft_printf("ft_printf - character: %c\n", *(name + 1));
	printf("printf - character: %c\n", *(name + 1));
	ft_putendl("------------------------------------");
}
