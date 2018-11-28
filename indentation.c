#include "ft_printf.h"

char	*add_ind(char *str, t_param *node)
{
	int		len;
	char	*new;

	//str = ft_strdup(str);
	//printf("str after: %s\n", str);
	if (node->conv != D || node->conv != O)
        str = add_prec(str, node);
	//printf("str after: %s\n", str);
	len = ft_strlen(str);
	if (len >= node->width)
		return (str);
	else
	{
		new = ft_strnew(1);
		while (node->width - len > 0)
		{
			if (node->ind == CLEAR/* || node->conv == S*/ || node->conv == P || node->conv == C || ft_strchr(node->flags, '-'))
				new = add_char(new, ' ');
			else
				new = add_char(new, '0');
			--(node->width);
		}
		if (ft_strchr(node->flags, '-'))
			new = fstrjoin(str, new);
		else
			new = fstrjoin(new, str);
		return (new);
	}
}

char	*add_prec(char *str, t_param *node)
{
	int		len;
	char	*new;
    
    //print_full_param(*node);
	if (!(node->conv > C && node->conv < F) && node->conv != P)
		return (str);
	if (node->ind == ZERO && node->precision > -1)
		node->ind = CLEAR;
	if (node->precision == 0 && node->conv != P)
		return (ft_strdup(" "));
	len = ft_strlen(str);
	if (len >= node->precision)
		return (str);
	else
	{
		new = ft_strnew(1);
		while (node->precision - len > 0)
		{
			new = add_char(new, '0');
			--(node->precision);
		}
		new = fstrjoin(new, str);
		return (new);
	}
}