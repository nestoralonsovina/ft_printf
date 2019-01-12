/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:28 by nalonso           #+#    #+#             */
/*   Updated: 2019/01/11 14:31:29 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"
#include <limits.h>

int		main(int ac, char **av)
{
	char *name = "Nestor";
	char *surname = "Alonso";



	if (0) {
		printf("%zd\n", -1);
		ft_printf("%zd\n", -1);
	}
	if (0) {
		double arg = 0.000000;
		int ret, ter;
		
		ret=   printf("   printf: |{%.15lf}{%.15lF}|\n", atof(av[1]), atof(av[1]));
		ter=ft_printf("ft_printf: |{%.15lf}{%.15lF}|\n", atof(av[1]), atof(av[1]));
		printf("ft_printf: %d printf: %d\n", ret, ter);
	}
	//printf("Flags test: "); ft_printf("%#10d");
	if (0)
	{
		ft_printf("%2c", (char)-26);
	}
	if (1) {
		int ret = 0, ter = 0;

		printf("printf: !%#-08x!", 42);
		ft_printf("ft_printf: !%#-08x!", 42);
		ter =    printf("   printf: |%-#16.2hhx|", -1503432331);
		ret = ft_printf("ft_printf: |%-#16.2hhx|", -1503432331);
		printf("!ft_printf: %d printf: %d\n", ret, ter);

		//ret = ft_printf("!%+015.10u!", 0);
		//ter = printf("!%+015.10u!", 0);
		//printf("!ret: %d ter: %d", ret, ter);
	}
	/*
	if (0)
	{
		long long		ioro = 2;
		void	*cry = NULL;
		int ret, ter;

		ret=   printf("   printf: %010.0lld|\n", ioro);
		ter=ft_printf("ft_printf: %010.0lld|\n", ioro);
		printf("printf: %d | ft_printf: %d\n", ret, ter);
		ret=   printf("   printf: %010.0p|\n", cry);
		ter=ft_printf("ft_printf: %010.0p|\n", cry);
		printf("printf: %d | ft_printf: %d\n", ret, ter);
		ret=   printf("   printf: %+02.1llX|\n", ioro);
		ter=ft_printf("ft_printf: %+02.1llX|\n", ioro);
		printf("printf: %d | ft_printf: %d\n", ret, ter);
		ret=   printf("   printf: %d|\n", 4294966796);
		ter=ft_printf("ft_printf: %d|\n", 4294966796);
		printf("printf: %d | ft_printf: %d\n", ret, ter);


	}
	if (0)
	{
		printf("{%-15Z}\n", 123);
		ft_printf("{%-15Z}\n", 123);	
		int n1, n2;
		ft_printf("hola me %s%n llamo nestor %n\n", "hola", &n1, &n2);
		printf("n1: %d n2: %d\n", n1, n2);	
	}
	if (0)
	{
		char *str = "Bonjour les amigos";
		int ret2 = ft_printf("{c}%s{R} {b}%s{R} {y}%s{R} {m}%s{R}", str, str, str, str);
		printf("\n(ret + colors): %d strlen: %d (strlen + color + reset): %d\n", ret2, ft_strlen(str), ft_strlen(str) + ft_strlen(RED) + ft_strlen(RESET));
		
	}
	if (0)
	{
		int *n;

		n = (int *)malloc(sizeof(int) * 10);
		for (int i = 0; i < 10; i++)
			printf("%ld\n", n++);
		//ft_printf("primero: %x  ultimo: %x resta: %x tamano int: %d\n", n, n + 10, 40, sizeof(int));
	}
	if (0)
	{
		unsigned int n = atoll(av[1]);
		ft_printf("Number %lld in binary is %b\n", n, n);
		ft_printf("Number %lld in hexadecimal is %x\n", n, n);
		ft_printf("Number %lld in octal is %o\n", n, n);
		ft_printf("Number %lld in decimal is %u\n", n, n);
		ft_printf("-------------Indentation and Precision------------\n");
		ft_printf("-----------ft_printf----------\n");
		ft_printf("Number %lld in hexadecimal is |%#5.3x|\n", n, n);
		ft_printf("Number %lld in octal is       |%#o|\n", n, n);
		ft_printf("Number %lld in decimal is     |%5.3u|\n", n, n);
		ft_printf("-----------printf----------\n");
		   printf("Number %lld in hexadecimal is |%#5.3x|\n", n, n);
		   printf("Number %lld in octal is       |%#o|\n", n, n);
		   printf("Number %lld in decimal is     |%5.3u|\n", n, n);
	
	}
	if (0)
	{
		ft_printf("@moulitest: %.d %.0d\n", 42, 43);
		printf("@moulitest: %.d %.0d\n", 42, 43);
		printf("{% 03d}\n", 15);
		ft_printf("{% 03d}\n", 15);
		ft_printf("%lld", -9223372036854775808);
	}
	if (0)
	{
		printf("%.2x\n", 42);
		ft_printf("%.2x\n", 42);
		printf("%#8x\n", 42);
		ft_printf("%#8x\n", 42);
	}
	if (0)
	{
		printf("{%f} {%F}\n", 1.4199999570846558, 1.4199999570846558);
		ft_printf("{%f} {%F}\n", 1.4199999570846558, 1.4199999570846558);
		printf("{%f} {%F}\n", -1.42, -1.42);
		ft_printf("{%f} {%F}\n", -1.42, -1.42);

	}
	if (0)
	{
		ft_printf("------------------------------\n");
		ft_printf("@ft-prt: %++ d\n", 42);
		   printf("@printf: %++ d\n", 42);
		ft_printf("------------------------------\n");
	}
	if (0)
	{
		ft_printf("@ft-prt: %5.x %5.0x|\n", 0, 0);
		   printf("@printf: %5.x %5.0x|\n", 0, 0);
		ft_printf("------------------------------\n");
		ft_printf("@ft-prt: %-#6o|\n", 2500);
		   printf("@printf: %-#6o|\n", 2500);
		ft_printf("------------------------------\n");
		ft_printf("@ft-prt: %#.x %#.0x\n", 0, 0);
		   printf("@printf: %#.x %#.0x\n", 0, 0);
		ft_printf("------------------------------\n");
		ft_printf("@ft-prt: %.d %.0d|\n", 42, 43);
		   printf("@printf: %.d %.0d|\n", 42, 43);
		ft_printf("------------------------------\n");
		ft_printf("@ft-ptr: %#.x %#.0x\n", 0, 0);
		   printf("@printf: %#.x %#.0x\n", 0, 0);
		ft_printf("------------------------------\n");
		ft_printf("@ft-ptr: %05d\n", 42);
           printf("@printf: %05d\n", 42);
		ft_printf("------------------------------\n");
		ft_printf("@ft-ptr: %#08x\n", 42);
		   printf("@printf: %#08x\n", 42);
		ft_printf("------------------------------\n");
		ft_printf("@ft-ptr: %#08x\n", 42);
		   printf("@printf: %#08x\n", 42);
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
		ft_printf("%ld", -2147483649);
		//ft_printf("ret ft_printf: %d ret printf: %d\n", ret, ret2);
	}
	if (0)
	{
		ft_printf("esto es mucha precision: %200d %50d", 5, 20);
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
		ft_printf("hola %s %s\n", "Nestor", "Alonso");
		ft_putchar('\n');
		ft_printf("hola hola");
	}
	if (0)
	{
		print_reverse(dec_to_hex(10000));
		ft_putchar('\n');
	}*/
	return (0);
}
