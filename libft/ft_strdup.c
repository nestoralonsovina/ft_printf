/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:50:04 by nalonso           #+#    #+#             */
/*   Updated: 2018/11/14 10:47:42 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *cpy;

	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (cpy != NULL)
		return (ft_strcpy(cpy, s1));
	return (cpy);
}
