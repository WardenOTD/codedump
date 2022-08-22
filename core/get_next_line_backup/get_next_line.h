/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:40 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/22 11:32:21 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char		*get_next_line(int fd);

char		*readfd(int fd, char *string);

char		*readstring(char *string);

char		*trim(char *string);

int			ft_strlen(const char *s);

char		*ft_strjoin(char *s1, char *s2);

int			check(char *string, int c);

char		*ft_strdup(const char *s1);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
