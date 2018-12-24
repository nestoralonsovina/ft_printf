#include "../includes/ft_printf.h"


static int		valid_color(t_printf *p)
{
	if (*p->inp == '{')
		if (*(p->inp + 1) && ft_strchr("RBArgybmcw",*(p->inp + 1)))
			if (*(p->inp + 2) && *(p->inp + 2) == '}')
				return (1);
	return (0);
}

void	colors(t_printf *p)
{
	char	*color;
	if (!valid_color(t_printf *p))
		return ;
	++p->inp;
	color = search_color(*p->inp);
	p->len += write(1, color, ft_strlen(color));
}
