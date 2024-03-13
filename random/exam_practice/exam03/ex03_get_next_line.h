#ifndef EX03_GET_NEXT_LINE_H
# define EX03_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*reading(char *everything, int fd);
int	nlcheck(char *ev);
char	*reallocbuff(char *buff, int rv);
int	ft_strlen(char *str);
char	*ft_strjoin(char	*ev, char *buff);
char	*get_line(char *ev);
char	*trim(char *ev);

#endif
