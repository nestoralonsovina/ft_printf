/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:38 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/21 18:25:35 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		is_conversion(char c)
{
	char flags[] = "cspfdiouxX";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

int		handle_conversions(char flags[], va_list al)
{
	int ret;
	
	ret = 0;
	if (ft_strchr(flags, 's'))
		ret += handle_str(flags, va_arg(al, char *));
	else if (ft_strchr(flags, 'p'))
		ret += handle_ptr(flags, va_arg(al, void *));
	else if (ft_strchr(flags, 'c'))
		ret += handle_char(flags, (char)va_arg(al, int));
	else if (ft_strchr(flags, 'l'))
		ret += handle_long(flags, al);
	else if (ft_strchr(flags, 'd') || ft_strchr(flags, 'i'))
		ret += handle_int(flags, al);
	else if (ft_strchr(flags, 'f'))
		ret += handle_float(flags, al);
	else if (ft_strchr(flags, 'o'))
		ret += handle_octal(flags, al);
	else if (ft_strchr(flags, 'u'))
		ret += handle_decimal(flags, al);
	else if (ft_strchr(flags, 'x') || ft_strchr(flags, 'X'))
		ret += handle_hexa(flags, al);
	return (ret);
}

void		*malloc_safe(size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
	{
		write(2, "malloc failure !\n", 17);
		exit(1);
	}
	return (tmp);
}

char	*add_char(char *str, char c)
{
	char 	*new;
	int		len;

	len = ft_strlen(str);
	new = (char *)malloc_safe(len + 2);
	new = ft_strcpy(new, str);
	new[len] = c;
	new[len + 1] = c;
	if (str)
		free(str);
	return (new);
}

char		ret_conversion(char *flags)
{
	char	posibles[] = "cspfdiouxX";
	int		i;
	
	i = 0;
	while (posibles[i])
	{
		if (ft_strchr(flags, posibles[i]) != NULL)
			return (posibles[i]);
		++i;
	}
	return ((char)0); 
}

void	search_width(t_param *new)
{
	int i;
	
	i = 0;
	new->width = 0;
	printf(YELLOW "Inside search_width()...\n" RESET );
	if (new->flags[i] == '0')
	{
		++i;
		new->ind = ZERO;
	}else if (ft_isdigit(new->flags[i]))
		new->ind = CLEAR;
	else
		new->ind = NONE;
	while (ft_isdigit(new->flags[i]))
	{
		new->width = new->width * 10 + new->flags[i] - '0';
		++i;
	}
	print_full_param(*new);
	printf(YELLOW "Exiting search_width()...\n" RESET);
}

void		search_precision(t_param *new)
{
	char	*ptr;
	int		i;
	
	i = 0;
	ptr = ft_strchr(new->flags, '.');
	new->precision = 0;
	if (ptr && ptr[i] == '.')
	{
		++i;
		while (ft_isdigit(ptr[i]))
		{
			
		}
	}
}

t_param		init_param(char *flags/*, va_list al*/)
{
	t_param		new;
	
	new.conversion = ret_conversion(flags);
	new.flags = flags;
	search_width(&new);
	search_precisio(&new);
	return (new);
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
			//res.curr = init_param(flags, al);
		}
		else
			res.buff = add_char(res.buff, *format);
		format += 1;
	}
	return (res.buff);
}

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int		done;
	char	*stdesp;

	va_start(arg, format);
	stdesp = handle_args(format, arg);
	va_end(arg);
	ft_putstr(stdesp);
	return (ft_strlen(stdesp));
}
