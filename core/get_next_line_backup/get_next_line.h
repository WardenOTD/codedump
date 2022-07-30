/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:40 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/30 10:09:17 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);

char		*readfile(int fd, char *string, int count);

size_t		ft_strlen(const char *s);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_getline(char *string, int count);

int			ccheck(char *string, int c);

int			checkcount(char *string, int c, int count);

#endif
