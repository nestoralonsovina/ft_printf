/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:12:05 by nalonso           #+#    #+#             */
/*   Updated: 2019/02/12 11:31:35 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name, char **env)
{
	size_t len;

	len = ft_strlen(name);
	if (env == NULL || name[0] == '\0')
		return (NULL);
	while (env && *env)
	{
		if (ft_strncmp(*env, name, len) == 0\
			&& *(*env + len) && *(*env + len) == '=')
			return (ft_strchr(*env, '=') + 1);
		env += 1;
	}
	return (0);
}
