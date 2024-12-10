# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int	ft_strchr(const char *str, char search_str);
char	*ft_strjoin(char const *s1, char const *s2);
char*   get_read_str(int fd, char*  s_str);
char* get_next_line(int fd);
char* get_remminder(char* s_str);

#endif