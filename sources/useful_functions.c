/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:11:31 by nalonso           #+#    #+#             */
/*   Updated: 2019/01/10 11:26:05 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*malloc_safe(size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
	{
		write(2, "malloc failure !\n", 17);
		exit(1);
	}
	return (tmp);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*add_char(char *str, char c)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	new = (char *)malloc_safe(len + 2);
	new[0] = c;
	while (str[i] != '\0')
	{
		new[i + 1] = str[i];
		++i;
	}
	new[i + 1] = '\0';
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

void	swap(char *start, char *end)
{
	char	tmp;

	tmp = *start;
	*start = *end;
	*end = tmp;
}

void	reverse(char str[], int length)
{
	int	start;
	int	end;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		swap((str + start), (str + end));
		start++;
		end--;
	}
}

char	*ft_itoa_base(unsigned long long num, int base)
{
	char	str[66];
	int		i;
	int		rem;

	i = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	str[i] = '\0';
	reverse(str, i);
	return (ft_strdup(str));
}
