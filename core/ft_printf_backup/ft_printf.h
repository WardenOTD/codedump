/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:41:33 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/13 15:30:05 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_flags
{
	int			printed;
}				t_flags;

typedef struct s_specifier
{
	int			c;
	int			s;
	int			p;
	int			di;
	int			u;
	int			x;
	int			upperx;
	int			hash;
}				t_specifier;

int				ft_printf(const char *str, ...);

int				percent(const char *str);

void			print(t_flags *flag);

void			default_flag(t_flags *flag);

void			default_specifier(t_specifier *spc);

int				out(t_specifier *spc, t_flags *flag,
					va_list list, const char *str);

char			*create_c(t_specifier *spc, va_list list);

void			free_check(char *cc);

void			write_to_fd(char *str, t_flags *flag, int fd);

int				if_hex(t_flags *flag, t_specifier *spc, va_list list);

int				if_pointer(t_flags *flag, va_list list);

char			*hex_convertp(unsigned long address);

void			phexx(char *cadd, unsigned long address, int count);

void			append_0x(char *str);

char			*hex_convert(t_specifier *spc, unsigned int address);

void			hexx(char *cadd, unsigned int address, int count);

void			uhexx(char *cadd, unsigned int address, int count);

int				if_char(t_flags *flag, va_list list);

int				if_int(t_specifier *spc, t_flags *flag, va_list list);

unsigned int	digitcount(unsigned int n);

char			*utoa(unsigned int n);

int				findspc(const char *str, t_specifier *spc);

int				findspc1(int str, int i, t_specifier *spc);

int				findspc2(int str, int i, t_specifier *spc);

int				findspc3(int str, int i, t_specifier *spc);

int				findspc4(int str, int i, t_specifier *spc);

#endif
