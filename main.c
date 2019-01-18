# include "includes/ft_printf.h"
# include <stdio.h>

int		main(void)
{
	
	float		f  = 1.42;
	double		d  = 1.42;
	long double	ld = 1.42;

	ft_printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", f, d, d, ld);
	printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", f, d, d, ld);
	ft_putendl(0);
	ft_printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", -f, -d, -d, -ld);
	printf("f: {%f} F: {%F} lf: {%lf} LF: {%LF}\n", -f, -d, -d, -ld);
	ft_putendl(0);

	int				i  = 42;
	unsigned int	ui = 42;
	long			li = 42;
	
	ft_printf("x: {%015.12lx} X: {%015.12lX} x: {%015.0lx} X: {%015.0lX}\n", li, li, li, li);
	printf("x: {%015.12lx} X: {%015.12lX} x: {%015.0lx} X: {%015.0lX}\n", li, li, li, li);
	ft_putendl(0);
	ft_printf("o: {%015.12lo} o: {%015.12lo} o: {%015.0lo} o: {%015.0lo}\n", li, li, li, li);
	printf("o: {%015.12lo} o: {%015.12lo} o: {%015.0lo} o: {%015.0lo}\n", li, li, li, li);
	ft_putendl(0);
	ft_printf("x: {%#015.0lx} X: {%#015.0X} x: {%#015.12lx} X: {%#015.12lX}\n", li, li, li, li);
	printf("x: {%#015.0lx} X: {%#015.0lX} x: {%#015.12lx} X: {%#015.12lX}\n", li, li, li, li);
	ft_putendl(0);
	ft_printf("o: {%#015.12lo} o: {%#015.12lo} o: {%#015.0lo} o: {%#015.0lo}\n", li, li, li, li);
	printf("o: {%#015.12lo} o: {%#015.12lo} o: {%#015.0lo} o: {%#015.0lo}\n", li, li, li, li);
	ft_putendl(0);

	i  = 0;
	ui = 0;
	li = 0;

	ft_printf("x: {%015.12lx} X: {%015.12lX} x: {%015.0lx} X: {%015.0lX}\n", li, li, li, li);
	printf("x: {%015.12lx} X: {%015.12lX} x: {%015.0lx} X: {%015.0lX}\n", li, li, li, li);
	ft_putendl(0);
	ft_printf("o: {%015.12lo} o: {%015.12lo} o: {%015.0lo} o: {%015.0lo}\n", li, li, li, li);
	printf("o: {%015.12lo} o: {%015.12lo} o: {%015.0lo} o: {%015.0lo}\n", li, li, li, li);
	ft_putendl(0);
	ft_printf("x: {%#015.0lx} X: {%#015.0X} x: {%#015.12lx} X: {%#015.12lX}\n", li, li, li, li);
	printf("x: {%#015.0lx} X: {%#015.0lX} x: {%#015.12lx} X: {%#015.12lX}\n", li, li, li, li);
	ft_putendl(0);
	ft_printf("o: {%#015.12lo} o: {%#015.12lo} o: {%#015.0lo} o: {%#015.0lo}\n", li, li, li, li);
	printf("o: {%#015.12lo} o: {%#015.12lo} o: {%#015.0lo} o: {%#015.0lo}\n", li, li, li, li);
	ft_putendl(0);

	void	*ptr = &i;
	void	*null = NULL;

	ft_printf("p: {%20p} p: {%5p} p: {%010p} p: {%10p}\n", ptr, ptr ,ptr , ptr);
	printf("p: {%20p} p: {%5p} p: {%10p} p: {%10p}\n", ptr, ptr ,ptr , ptr);
	ft_putendl(0);
	ft_printf("p: {%20p} p: {%5p} p: {%10p} p: {%10p}\n", null, null, null, null);
	printf("p: {%20p} p: {%5p} p: {%10p} p: {%10p}\n", null, null, null, null);
	ft_putendl(0);

	return (0);
}

