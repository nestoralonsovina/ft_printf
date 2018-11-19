#include "ft_printf.h"

static void	print_hex(long nb)
{
	if (nb >= 16)
		print_hex(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar('a' + (nb % 16) - 10);
	else
		ft_putchar((nb % 16) + '0');
}

int		handle_ptr(char *flags, void *pointer)
{
	int		hex;
	
	if (*flags == 'p')
	{
		if (*(flags + 1) == '\0')
		{
			write(1, "0x", 2);
			print_hex((long)pointer);
		}
	}
	return (123);
}