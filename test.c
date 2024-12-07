/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:04:07 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/04 17:42:08 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    s_list      *list;
    s_list      *node;
    static char *s_str;

    s_str = NULL;
    list = ft_lstnew(&s_str);
    node = list;
    if (fd < 0)
        return (0);
    while (list)
    {
        if (list->BUFFER == NULL)
        {
            list->BUFFER = malloc((BUFFER_SIZE + 1) * sizeof(char));
            if (!list->BUFFER)
                return (free_all_alcoted(node, list));
            if (!read(fd, list->BUFFER, BUFFER_SIZE))
                break;
        }
        if (check_is_new_line(list->BUFFER))
            return (get_string(node, &s_str, '\n'));
        list->next = ft_lstnew(&s_str);
        list = list->next;
    }
    return (get_string(node, &s_str, '\0'));
}