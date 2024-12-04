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


char*  free_all_alcoted(s_list* head,s_list* list)
{
    s_list *temp;

    temp = head;
    while (head)
    {
        if (head != list)
            free(head->BUFFER);
        temp = head;
        head = head->next;
        free(temp);
    }
    return (NULL);
}

int check_is_new_line(char* str)
{
    while (*str )
    {
        if (*str != '\n')
            return (1);
        str++;
    }
    return (0);
}

void len_str_on_node_and_get_lastnod(s_list* node,size_t *len,size_t* len_rest,char c)
{
    char *str;
    s_list* head;

    head = node;
    while (node->next)
    {
        *len +=  ft_strlen(node->BUFFER);
        node = node->next;
    }
    str = node->BUFFER;
    while (*str)
    {
        *len++;
        if(*str == '\n' || *len_rest != 0)
        {
            *len--;
            *len_rest++;
        }
        str++;
    }
    free_all_alcoted(head,node->next);
}

char* get_just_str(s_list* node,size_t len,char c)
{
	s_list *head;
	char* str;

	head = node;
	str = malloc((len + 1) + sizeof);
	if (!str)
		return (free_all_alcoted(node,NULL),NULL);
	while(head)
	{
		while (*(head->BUFFER) && i < len)
		{
			str[i] = *(head->BUFFER);
			i++;
			head->BUFFER++;
		}
		head = head->next;
	}
	str[i + 1] = c;
	str[i + 2] = '\0';
	free_all_alcoted(node,NULL);
	return (str);
}

char* get_string(s_list* node,char** s_str,char c)
{
    size_t len;
    size_t len_rest;
    char* str;
    s_list* head;
    size_t i;

    len = 0;
    len_rest = 0;
    i = 0 ;
    head = node;
    len_str_on_node_and_get_lastnod(node,&len,&len_rest,c);
    while (head->next)
        head = head->next;
    **s_str = malloc((len_rest + 1) * sizeof(char));
    if(!**s_str)
        return (free_all_alcoted(head,node->next),NULL);
    *s_str[len_rest] = '\0';
    while (i < len_rest)
    {
	*s_str[i] = head->BUFFER[(ft_strlen(head->BUFFER) - len_rest) + i];
	i++;
    }
    str = get_just_str(node,len,c);
    free_all_alcoted(node,NULL);
    return(str);
}

char*   get_next_line(int fd)
{
    s_list *list;
    s_list *node;
    static char* s_str;

    s_str = NULL;
    list = ft_lstnew();
    node = list;
    if (fd < 0)
        return (0);
    while (list)
    {
        list->BUFFER = malloc(BUFFER_SIZE * sizeof(char ));
        if (!list->BUFFER)
            return (free_all_alcoted(node,list));
        if(!read(fd,list->BUFFER,BUFFER_SIZE))
            break;
        if (check_is_new_line(list->BUFFER))
            return (get_string(node,&s_str,'\n'));

        list->next = ft_lstnew();
    }
    return (get_string(node,&s_str,'\0'));
}

int main()
{
    int i = 0;
    int fd = open("text.txt",O_RDWR,0644);

    char *BUFFER = get_next_line(fd);
    char *BU = get_next_line(fd);

    printf("--> %s \n",BUFFER);
    printf("--> %s\n",BU);

}
