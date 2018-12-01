#include "ft_printf.h"

int		is_conversion(char c)
{
	char flags[] = "cspfdiouxX";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}
void	convert_arg(t_param *curr, t_printf *head)
{
	if (curr->conv == S)
		handle_str(curr);
	else if (curr->conv == P)
		handle_ptr(curr);
	else if (curr->conv == D || curr->conv == I)
		handle_integer(curr);
	else if (curr->conv == O)
		handle_octal(curr);
	else if (curr->conv == X || curr->conv == BIGX)
		handle_hexa(curr);
	else if (curr->conv == U)
		handle_u(curr);
	else if (curr->conv == C)
		handle_c(curr, head);
}

t_printf	*handle_args(const char *format, va_list al)
{
	char		flags[12];
	int			i;
	t_printf	*res;

	i = 0;
	
	res = (t_printf *)malloc(sizeof(*res));
	res->buff = ft_strdup("");
	res->len = 0;
	while (*format)
	{
		ft_bzero(flags ,12);
		if (*format == '%' && *(++format) != '%') // posible seg fault if i try to access uninitialize memory
		{
			while (!is_conversion(*format) && *format)
			{
				flags[i++] = *format++;
			}
			flags[i] = *format;
			i = 0;
			//printf("%s\n", flags);  // debug stored flags
			res->curr = init_param(flags, al);
			convert_arg(res->curr, res);
			if (res->curr->conv != C) // I'm handling char personally because they are incredible.
			{
				res->len += write(1, res->curr->pf_string, ft_strlen(res->curr->pf_string));
				free(res->curr->pf_string);
			}
			free(res->curr->flags);
			free(res->curr);
		}
		else
			res->len += write(1, format, 1);
		format += 1; // posible segfault
	}
	return (res);
}

