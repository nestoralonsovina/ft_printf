#include "ft_printf.h"

int		handle_str(char *flags, char *str)
{
	char	*ptr;

	ptr = str;
	if (*flags == 's')
	{
		if (*(flags + 1) == '\0')
		{
			if (str)
				while (*str)
					write(1, str++, 1);
		}
	}
	return (str - ptr);
}
