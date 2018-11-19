#include "ft_printf.h"

int		handle_char(char *flags, char c)
{
	if (*flags == 'c' && c)
	{
		if (*(flags + 1) == '\0')
			write(1, &c, 1);
	}
	else
		return (0);
	return (1);
}