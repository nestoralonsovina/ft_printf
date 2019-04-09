/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:25:18 by nalonso           #+#    #+#             */
/*   Updated: 2019/04/09 12:20:58 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000000

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);
int		gnl_stdout(char **line);
int		ft_getc(int fd);
int		ft_getdelim(char **lineptr, size_t *n, int delim, int stream);
int		ft_getline(char **lineptr, size_t *n, int stream);

#endif
