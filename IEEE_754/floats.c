#include <stdio.h>
#include "../ft_printf.h"

# define printd(x) printf("%d\n", x);

union	ufloat {
	float f;
	unsigned u;
};

union	udouble {
	double d;
	unsigned long u;
};


int		main(void)
{
	double			a;
	unsigned long	*b;
	unsigned		sign;
	unsigned char	uc;
	int				z = 63;
	union udouble ud;;

	a = 1.54245;
	ud.d = a;
	ft_printf("%b", ud.u);
}
