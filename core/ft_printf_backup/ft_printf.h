/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:41:33 by jteoh             #+#    #+#             */
/*   Updated: 2022/11/29 10:50:19 by jteoh            ###   ########.fr       */
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

void			default_flag(t_flags *flag);

void			default_specifier(t_specifier *spc);

#endif
