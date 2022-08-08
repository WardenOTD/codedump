/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:40 by jteoh             #+#    #+#             */
/*   Updated: 2022/08/04 10:46:29 by jteoh            ###   ########.fr       */
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

int			setarr(char **arr, int fd);

int			thelinepartofgnl(char **arr, char *line);

int			linep1(int i, int m, int n, char **arr, char *line);

int			linep2(int i, int m, int n, char **arr, char *line);

int			scuffedrealloc(char **arr, int i);

int			ft_strlen(const char *s);

char		*ft_strdup(char *dest, const char *s1);

int			check(char *string, int c);

int			freeall(char **arr);

#endif
