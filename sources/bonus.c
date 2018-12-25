#include "../includes/ft_printf.h"


/*
** Support for the following bonus:
**   1. Colors
**   2. %n flag, stores in the argument of the type (int *) the current len printed.
**   3. %UDO flags, the correspond to %lu %ld and %lo.
**   4. %b flag, to print an unsigned number in binary TODO: add signed numbers support. If possible without making to much of a mess.
**   5. %aA %eE flags to print hexadecimal and octal numbers in decimal notation. TODO: everything
**   6. Posible addition: support for %lc and %ls to print wide characters. TODO: everything too
*/


static int		valid_color(t_printf *p)
{
	if (*p->inp == '{')
		if (*(p->inp + 1) && ft_strchr("RBrgybmcw", *(p->inp + 1)))
			if (*(p->inp + 2) && *(p->inp + 2) == '}')
				return (1);
	return (0);
}

static char		*search_color(char cl)
{
	if (cl == 'B')
		return (BLACK);
	else if (cl == 'r')
		return (RED);
	else if (cl == 'g')
		return (GREEN);
	else if (cl == 'y')
		return (YELLOW);
	else if (cl == 'b')
		return (BLUE);
	else if (cl == 'm')
		return (MAGENTA);
	else if (cl == 'c')
		return (CYAN);
	else if (cl == 'w')
		return (WHITE);
	else
		return (RESET);
}

int				colors(t_printf *p)
{
	char	*color;

	if (valid_color(p))
	{
		++p->inp;
		color = search_color(*p->inp);
		p->len += write(1, color, ft_strlen(color));
		++p->inp;
		return (1);
	}
	return (0);
}
