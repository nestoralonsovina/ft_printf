/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:28 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/23 11:55:38 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void		print_full_param(t_param curr)
{
	printf(YELLOW "printf_full_param() starting...\n" RESET);
	//printf("pf_string: %s\n", curr.pf_string);
	printf("conversion: %c\n", curr.conversion);
	printf("conv enum: %d\n", curr.conv);
	printf("flags: %s\n", curr.flags);
	printf("width: %d\n", curr.width);
	printf("precision: %d\n", curr.precision);
	printf("ind: %d\n", curr.ind);
	printf("mod: %d\n", curr.mod);
	printf("stored data: %d\n", curr.data.sc);
	printf(YELLOW "printf_full_param() ended...\n" RESET);
	}

int		main(void)
{
	char *name = "Nestor";
	char *surname = "Alonso";
	
	//printf("Flags test: "); ft_printf("%#10d");
	if (0)
	{
		ft_printf(RESET "itoa_base: %s\n" RESET, ft_itoa_base(100 , 10));
	}
	if (0)
	{
		int ret1;
		int ret2;
		
		int i = 1015;
	 ret1 = ft_printf(RESET "digit %20x string %10s\n" RESET, i, name);
		ret2 = printf(RESET "digit %20x string %10s\n" RESET, i, name);
		printf("are the returns equal? %d\n", ret1 == ret2);
	}
	if (1)
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
	if (0)
	{
		t_param		new;
		char		*flags;
		
		flags = "010.3hhu";
		//new = init_param(flags);
		print_full_param(new);
	}
	if (0)
	{
		char *str = "hola";
		while (ft_strlen(str) < 10)
			str = add_char(ft_strdup(str), 'a');
		printf("%s\n", str);
		free(str);
	}
	if (0)
	{
		print_reverse(dec_to_hex(10000));
		ft_putchar('\n');
	}
	return (0);
}
