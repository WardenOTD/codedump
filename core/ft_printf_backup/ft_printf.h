/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:41:33 by jteoh             #+#    #+#             */
/*   Updated: 2022/09/01 11:15:24 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);

int				minimum_width(const char *str, int i, va_list list, t_list *count);

int				rolecall(const char *str, int i, va_list list, t_list *count, char *output);

char			get_char(va_list list);

char			*get_str(va_list list);

char			*get_ptr(va_list list);

char			*clear_buffered_0(char *str);

char			*address_hex(va_list list);

char			*add0x(char *address);

char			*get_hex_lower(va_list list);

char			*get_hex_upper(va_list list);

void			hex_helper(char **hexed, unsigned long j, unsigned long q, int l, char *hex);

char			*get_deci_int(va_list list);

char			*get_unsigned(va_list list);

void			unsigned_helper(char **arr, unsigned int uni, unsigned int tmp, int l);

#endif
