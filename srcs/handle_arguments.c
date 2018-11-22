#include "ft_printf.h"

int		is_conversion(char c)
{
	char flags[] = "cspfdiouxX";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}


char	*handle_args(const char *format, va_list al)
{
	char		flags[12];
	int			i;
	t_printf	res;
		
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(++format) != '%') // posible seg fault if i try to access uninitialize memory
		{
			while (!is_conversion(*format) && *format)
			{
				flags[i++] = *format++;
			}
			flags[i] = *format;
			i = 0;
			// printf("%s\n", flags);  // debug stored flags
			res.curr = init_param(flags, al);
		}
		else
			res.buff = add_char(res.buff, *format);
		format += 1;
	}
	return (res.buff);
}

