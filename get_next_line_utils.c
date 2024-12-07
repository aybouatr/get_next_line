#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

s_list *ft_lstnew(char **str_s)
{
    s_list *list;

    list = (s_list *)malloc(sizeof(s_list));
    if (!list) 
        return NULL; 
    list->next = NULL;
    if (*str_s != NULL) {
        list->BUFFER = *str_s;
        *str_s = NULL;          
    }
    else 
        list->BUFFER = NULL;    

    return list; 
}