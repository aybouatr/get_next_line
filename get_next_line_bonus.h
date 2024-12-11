/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:05:21 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/11 09:05:24 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strchr(const char *str, char search_str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_read_str(int fd, char *s_str);
char	*get_read_str(int fd, char *s_str);
char	*get_next_line(int fd);
char	*get_remminder(char *s_str);

#endif
