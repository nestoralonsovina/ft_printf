#include "ft_printf.h"

int		is_conversion(char c)
{
	char flags[] = "cspfdiouxX";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}
void	convert_arg(t_param *curr)
{
	if (curr->conv == S)
		handle_str(curr);
	else if (curr->conv == P)
		handle_ptr(curr);
	else if (curr->conv == D || curr->conv == I)
		handle_integer(curr);
}

char	*handle_args(const char *format, va_list al)
{
	char		flags[12];
	int			i;
	t_printf	res;

	i = 0;
	res.buff = ft_strdup("");
	while (*format)
	{
		ft_strclr(flags);
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
			convert_arg(res.curr);
			res.buff = fstrjoin(res.buff, res.curr->pf_string);
			free(res.curr);
		}
		else
			res.buff = add_char(res.buff, *format);
		format += 1; // posible segfault
	}
	return (res.buff);
}

