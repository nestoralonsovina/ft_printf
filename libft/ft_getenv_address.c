/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:46 by nalonso           #+#    #+#             */
/*   Updated: 2019/02/12 11:12:22 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_getenv_address(const char *name, char **env)
{
	size_t len;

	len = ft_strlen(name);
	if (env == NULL || name[0] == '\0')
		return (NULL);
	while (env && *env)
	{
		if (ft_strncmp(*env, name, len) == 0\
			&& *(*env + len) && *(*env + len) == '=')
			return (env);
		env += 1;
	}
	return (env);
}
