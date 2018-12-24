/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalonso <nalonso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:23:56 by nalonso           #+#    #+#             */
/*   Updated: 2018/12/24 11:16:44 by nalonso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/libft.h"
#include <stdio.h>

# define NONE (1 << 0)
# define CLEAR (1 << 1)
# define ZERO (1 << 2)
# define MINUS (1 << 3)
# define PLUS (1 << 4)
# define SPACE (1 << 5)
# define SHARP (1 << 6)
# define PRECISION (1 << 7)
# define NEGATIVE (1 << 8)

typedef union	u_data
{
	int					i;
	unsigned int		ui;
	char				c;
	void				*ptr;
	char				*str;
	signed char			sc;
	unsigned char		uc;
	short				s;
	unsigned short		us;
	long				l;
	long long			ll;
	unsigned long		ul;
	unsigned long long	ull;
	double				d;
	long double			ld;
}				t_data;

typedef enum	e_modifiers
{
	NO = 0, L = 1, H = 2, LL = 3, HH = 4, BIGL = 5
}				t_modifiers;

typedef enum	e_conversion
{
	NON, S, P, C, D, I, O, U, X, BIGX, B, F, N
}				t_conversion;

typedef struct	s_param
{
	char			*pf_string;
	char			conversion;
	char			*flags;
	int				width;
	int				precision;
	short				ind;
	t_modifiers		mod;
	t_conversion	conv;
	t_data			data;
}				t_param;

typedef struct	s_printf
{
	const char		*inp;
	int				len;
	t_param			*curr;
}				t_printf;

int				ft_printf(const char *format, ...);
t_printf		*handle_args(const char *format, va_list arg);
int				handle_conversions(char flags[], va_list al);

/*
**	USEFUL FUNCTIONS
*/

char			*fstrjoin(char *s1, char *s2);
void			*malloc_safe(size_t size);
char			*add_char(char *str, char c);
char			*data_to_base(t_param *node, int base);
char			*ft_strndup(const char *s1, size_t n);

/*
**	MANAGE PARAMETERS
*/

t_param		*init_param(char *flags, va_list al);
char		ret_conversion(char *flags, t_param *curr);
int			is_conversion(char c);
void		search_width(t_param *new);
void		search_precision(t_param *new);
void		search_modifier(t_param *new);

/*
**	DEBUG
*/
void		set_conversion(char con, t_param *curr);


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void		print_full_param(t_param curr);
char		*dec_to_hex(int nb);
void		print_reverse(char *str);
char		*ft_itoa_base(unsigned long long value, int base);
char		*ft_decimal_itoa(long long nbr);
// FUNCTIONS TO HANDLE DIFFERENT FLAGS

void			handle_ind(char *res, t_param *node);
char			*add_ind(char *str, t_param *node);
char			*add_prec(char *str, t_param *node);
void			handle_str(t_param *node);
void			handle_ptr(t_param *node);
void			handle_integer(t_param *node);
void			handle_octal(t_param *node);
void			handle_hexa(t_param *node);
void			handle_u(t_param *node);
void			handle_c(t_param *node, t_printf *head);
void			handle_float(t_param *a);
void			handle_binary(t_param *n);
void			handle_base(t_param *n, unsigned int base);
/*
**	LIBFT FUNCTIONS
*/
/*
char				*ft_itoa(int nbr);
int					ft_isdigit(int c);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strclr(char *s);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
void				ft_putstr(char *str);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *str, const char *to_find);
void			*ft_memset(void *b, int c, size_t len);
*/
#endif
