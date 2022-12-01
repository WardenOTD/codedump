/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:41:33 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/01 16:34:02 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int			neg;
	int			pos;
	int			hash;
	int			printed;
	char		*extract;
	char		*output;
	int			extract_size;
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

void			print(t_flags *flag);

void			default_flag(t_flags *flag);

void			default_specifier(t_specifier *spc);

int				out(t_specifier *spc, t_flags *flag, va_list list, const char *str);

char			*create_c(t_specifier *spc, va_list list);

void			fillspace(t_flags *flag);

void			cmp(t_flags *flag, char *cc);

void			other(t_specifier *spc, t_flags *flag);

int				if_hex(t_flags *flag, t_specifier *spc, va_list list);

char			*hex_convert(t_specifier *spc, unsigned long address);

void			hexx(char **cadd, unsigned long address, int count);

void			uhexx(char **cadd, unsigned long address, int count);

int				if_char(t_flags *flag, va_list list);

void			neg(t_flags *flag);

void			pos(t_flags *flag);

int				minimum(t_flags *flag);

int				cnc(const char *str, t_specifier *spc, t_flags *flag);

void			hard_set(t_specifier *spc, t_flags *flag);

int				findspc(const char *str, t_specifier *spc);

int				findspc2(const char *str, t_specifier *spc);

int				findspc3(const char *str, t_specifier *spc);

int				findspc4(const char *str, t_specifier *spc);

#endif
