#include "../../ft_printf.h"

void print_reverse(char *str)
{
	if (*str)
	{
		print_rever(str + 1);
		write(1, str, 1);
	}	
}

char	get_hex_value(int value)
{
	if (value < 0) return -1;
	if (value > 16) return -1;
	if (value <= 9) return '0' + value;
	value -= 10;
	return ('A' + value);
}

char	*dec_to_hex(int nb)
{
	char	str[16];
	int		i;

	i = 0;
	ft_bzero(str, 16);
	while (nb)
	{
		str[i++] = get_hex_value(nb % 16);
		nb /= 16;	
	}
	return (str);	
}

int     handle_hexa(char *flags, va_list al)
{
	char	*hex;
	int		ret;

	hex = dec_to_hex(va_arg(al, int));
	ret = ft_strlen(hex);
	reverse(hex);	
    return (ret);
}
