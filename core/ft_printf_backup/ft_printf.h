/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:41:33 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/30 10:49:54 by jteoh            ###   ########.fr       */
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

int				print_char(const char *str, int i, va_list list, t_list *count);

int				print_str(const char *str, int i, va_list list, t_list *count);

int				print_ptr(const char *str, int i, va_list list, t_list *count);

char			*clear_buffered_0(char *str);

int				print_hex_lower(const char *str, int i, va_list list, t_list *count);

int				print_hex_upper(const char *str, int i, va_list list, t_list *count);

void			hex_helper(char **hexed, long int j, long int q, int l, char *hex);

int				print_deci_int(const char *str, int i, va_list list, t_list *count);

#endif
