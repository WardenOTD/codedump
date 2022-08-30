/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:41:33 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 17:16:18 by jteoh            ###   ########.fr       */
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

int				rolecall(const char *str, int i, va_list list, t_list *count);

int				print_char(int i, va_list list, t_list *count);

int				print_str(int i, va_list list, t_list *count);

int				print_ptr(int i, va_list list, t_list *count);

char			*clear_buffered_0(char *str);

int				address_hex(va_list list, t_list *count);

int				print_hex_lower(int i, va_list list, t_list *count);

int				print_hex_upper(int i, va_list list, t_list *count);

void			hex_helper(char **hexed, unsigned long j, unsigned long q, int l, char *hex);

int				print_deci_int(int i, va_list list, t_list *count);

int				print_unsigned(int i, va_list list, t_list *count);

void			unsigned_helper(char **arr, unsigned int uni, unsigned int tmp, int l);

#endif
