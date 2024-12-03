#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

s_list* ft_lstnew()
{
    s_list* list;

    list = (s_list *)malloc(sizeof(s_list));
    if(!list)
        return (NULL);
    list->next = NULL;
    return (list);
}

