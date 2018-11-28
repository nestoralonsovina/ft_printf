/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:28 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/28 14:23:05t s by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include <limits.h>

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
	printf("stored data: %hd\n", curr.data.s);
	printf(YELLOW "printf_full_param() ended...\n" RESET);
	}

int		main(void)
{
	char *name = "Nestor";
	char *surname = "Alonso";

	//printf("Flags test: "); ft_printf("%#10d");
	if (0)
	{
		t_indentation e = ZERO | AFTER;
		printf("%d\n", e & ZERO);
	}
	if (1)
	{
		//printf("@moulitest: %5.x %5.0x|\n", 0, 0);
		//ft_printf("@moulitest: %5.x %5.0x|\n", 0, 0);
		//ft_printf("%-#6o|\n", 2500);
		//   printf("%-#6o|\n", 2500);
		//ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
		ft_printf("@moulitest: %.2o %.0o %.o|\n", 0, 0, 0);
		ft_printf("@moulitest: %#.o %#.0o|\n", 0, 0);
		ft_printf("@moulitest: %.10o|\n", 42);
		printf("@moulitest: %.2o %.0o %.o|\n", 0, 0, 0);
		printf("@moulitest: %#.o %#.0o|\n", 0, 0);
		printf("@moulitest: %.10o|\n", 42);
	}	
	if (0)
	{
		ft_printf("% d\n", 42);
		ft_printf("%0+5d\n", 42);
		   printf("%0+5d\n", -42);
		   printf("%0+5d\n", 42);
		   printf("%zi\n", LLONG_MIN);
	}
	if (0)
	{
		int		ret =  ft_printf("@ft_printf :|%5.2c||null: %c||%2.5c|\n", 42, 0, 42);
		int		ret2 =    printf("@printf    :|%5.2c||null: %c||%2.5c|\n", 42, 0, 42);
		void	*ptr = NULL;
		ft_printf("ret ft_printf: %d ret printf: %d\n", ret, ret2);
	    ret =  ft_printf("ft_printf: %.5p|%.p|%.0p|%9.2p|%2.9p\n", ptr, ptr, ptr, 1234, 1234);
		ret2 =    printf("libprintf: %.5p|%.p|%.0p|%9.2p|%2.9p\n", ptr, ptr, ptr, 1234, 1234);
		ft_printf("ret ft_printf: %d ret printf: %d\n", ret, ret2);
	}
	if (0)
	{
		void	*ptr = NULL;
	 ft_printf("ft_printf: %.5p|%.p|%.0p|%9.2p|%2.9p\n", ptr, ptr, ptr, 1234, 1234);
		printf("libprintf: %.5p|%.p|%.0p|%9.2p|%2.9p\n", ptr, ptr, ptr, 1234, 1234);
	}
	if (0)
	{
		ft_printf("% 0+-#10.5lld\n", 42);
		printf("% 0+-#10.5lld\n", 42);
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