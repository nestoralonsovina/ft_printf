/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:28 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/21 18:38:17 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void		print_full_param(t_param curr)
{
	printf("pf_string: %s\n", curr.pf_string);
	printf("conversion: %c\n", curr.conversion);
	printf("flags: %s\n", curr.flags);
	printf("width: %d\n", curr.width);
	printf("precision: %d\n", curr.precision);
	printf("ind: %d\n", curr.ind);
	printf("mod: %d\n", curr.mod);
}

int		main(void)
{
	char *name = "Nestor";
	char *surname = "Alonso";
	
	//printf("Flags test: "); ft_printf("%#10d");
	if (0)
	{	
		printf(" test return : %d\n", printf("Hola mu buenas%s", name) == ft_printf("Hola mu buenas%s", name));
		ft_putendl("------------------------------------");	
		printf("test double %%s%s he\n", name);	
		ft_putendl("------------------------------------");	
		ft_putendl("Test %%s flag:");
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
	if (1)
	{
		t_param		new;
		char		*flags;
		
		flags = "010.3hhd";
		new = init_param(flags);
		print_full_param(new);
	}
	return (0);
}
