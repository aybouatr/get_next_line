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

#include "get_next_line.h"

char *free_all_alcoted(s_list *head, s_list *list)
{
    s_list *temp;

    while (head)
    {
        temp = head;
        if (head != list)
            free(head->BUFFER);
        head = head->next;
        free(temp);
    }
    return (NULL);
}

int check_is_new_line(const char *str)
{
    if (!str)
        return (0);
    while (*str)
    {
        if (*str == '\n')
            return (1);
        str++;
    }
    return (0);
}

void len_str_on_node_and_get_lastnod(s_list *node, size_t *len, size_t *len_rest, char c)
{
    char *str;
    s_list *head;

    *len = 0;
    head = node;
    while (node->next)
    {
        *len += ft_strlen(node->BUFFER);
        node = node->next;
    }

    str = node->BUFFER;
    while (str && *str)
    {
        if (*str == '\n' || *len_rest != 0)
            (*len_rest)++;
        else
            (*len)++;
        str++;
    }
}

char *get_just_str(s_list *node, size_t len, char c)
{
    s_list *head;
    char *str;
    size_t i;
    char *buffer_pos;

    i = 0;
    head = node;
    str = malloc(len + 2); // +1 for c, +1 for null terminator
    if (!str)
        return (free_all_alcoted(node, NULL));

    while (head && i < len)
    {
        buffer_pos = head->BUFFER;
        while (buffer_pos && *buffer_pos && i < len)
        {
            str[i++] = *buffer_pos++;
        }
        head = head->next;
    }

    str[i] = c;
    str[i + 1] = '\0';

    free_all_alcoted(node, NULL);
    return (str);
}

char *get_last_list(s_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst->BUFFER);
}

char *get_string(s_list *node, char **s_str, char c)
{
    size_t len;
    size_t len_rest;
    char *str;
    s_list *head;
    char *str_last;
    char *s;
    size_t i;

    len = 0;
    len_rest = 0;
    i = 0;
    head = node;
    len_str_on_node_and_get_lastnod(head, &len, &len_rest, c);
    str_last = get_last_list(node);
    s = malloc((len_rest + 1) * sizeof(char));
    if (!s)
        return (NULL);
    s[len_rest] = '\0';
    while (i < len_rest)
    {
        s[i] = str_last[(ft_strlen(str_last) - len_rest) + i];
        i++;
    }
    str = get_just_str(node, len, c);
    return (str);
}

char *get_next_line(int fd)
{
    s_list      *list;
    s_list      *node;
    static char *s_str;

    s_str = NULL;
    list = ft_lstnew(&s_str);
    node = list;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
    while (list)
    {
        if (list->BUFFER == NULL)
        {
            list->BUFFER = malloc((BUFFER_SIZE + 1) * sizeof(char));
            if (!list->BUFFER)
                return (free_all_alcoted(node, list));
            if (!read(fd, list->BUFFER, BUFFER_SIZE))
                return (get_string(node, &s_str, '\0'));
        }
        if (check_is_new_line(list->BUFFER))
            return (get_string(node, &s_str, '\n'));
        list->next = ft_lstnew(&s_str);
        list = list->next;
    }
    return (get_string(node, &s_str, '\0'));
}

int main()
{
    int i = 0;
    int fd = open("text.txt", O_RDWR, 0644);

    char *BUFFER = get_next_line(fd);
     char *BU = NULL;
     
    printf("--> %s", BUFFER);

    BU = get_next_line(fd);

     printf("--> %s",BU);
}
