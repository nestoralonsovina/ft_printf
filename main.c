# include "includes/ft_printf.h"
# include <stdio.h>

int		main(void)
{
	
	float		f  = 1.42;
	double		d  = 1.42;
	long double	ld = 1.42;

	ft_printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", f, d, d, ld);
	printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", f, d, d, ld);

	ft_printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", -f, -d, -d, -ld);
	printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", -f, -d, -d, -ld);

	int		i  = 42;
	unsigned int	ui = 42;
	long int	li = 42;
	
			
	return (0);
}

