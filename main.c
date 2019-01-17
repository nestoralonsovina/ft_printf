# include "includes/ft_printf.h"
# include <stdio.h>

int		main(void)
{
	
	float		f = 1.42;
	double		d = 1.42;
	long double	ld= 1.42;

	ft_printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}", f, d, d, ld);
	printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}", f, d, d, ld);
	
	return (0);
}

