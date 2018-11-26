/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:11:31 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/25 16:56:14 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	new[len + 1] = '\0';
	if (str)
		free(str);
	return (new);
}

char	*fstrjoin(char *s1, char *s2)
{
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (ptr);
}

void	swap(char *c1, char *c2)
{
	char	tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap((str+start), (str+end));
        start++;
        end--;
    }
}

char	*ft_itoa_base(unsigned long num, int base)
{
	char str[66];
	int i = 0;
	int rem;

	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num/base;
	}
	str[i] = '\0';
	reverse(str, i);
	return (ft_strdup(str));
}
