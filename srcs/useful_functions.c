/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:11:31 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/22 14:35:00 by nalonso          ###   ########.fr       */
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