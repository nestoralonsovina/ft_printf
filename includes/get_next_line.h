/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:58:06 by nalonso           #+#    #+#             */
/*   Updated: 2019/03/02 14:04:52 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);
int		simple_gnl(char **line);

#endif
