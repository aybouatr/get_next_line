/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:17 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/03 11:30:21 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct t_list {

    char *BUFFER;
    struct t_list* next;

}s_list;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

size_t ft_strlen(char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
s_list* ft_lstnew();

#endif