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
#define BUFFER_SIZE 5
#endif

size_t ft_strlen(char *str);
char*  free_all_alcoted(s_list* head,s_list* list);
s_list* ft_lstnew();
void len_str_on_node_and_get_lastnod(s_list* node,size_t *len,size_t* len_rest,char c);
char* get_just_str(s_list* node,size_t len,char c);
char* get_string(s_list* node,char** s_str,char c);

#endif