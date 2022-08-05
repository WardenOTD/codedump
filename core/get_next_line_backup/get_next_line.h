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

char		**readfile(int fd, char **arr);

size_t		ft_strlen(const char *s);

char		*ft_strdup(const char *s1);

char		*ft_getline(char **arr, char *line);

char		*glhelper(char **arr, int i, int j, char *line, int m);

int			ccheck(char *string, int c, char **arr, int type);

char		**arrset(char **arr);

void		duplicatearr(char **tmp, char **arr);

#endif
