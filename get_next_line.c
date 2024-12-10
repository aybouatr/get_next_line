/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:28:06 by aybouatr          #+#    #+#             */
/*   Updated: 2024/12/10 10:28:10 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char*   get_read_str(int fd, char*  s_str)
{
    char*      buffer;
    ssize_t    len_resd;

    len_resd = 1;
    buffer = NULL;
    while (!ft_strchr(s_str, '\n') && len_resd != 0)
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if(!buffer)
            return (NULL);
        len_resd = read(fd, buffer,BUFFER_SIZE);
        if (len_resd == -1)
            return (free(buffer),NULL);
        s_str = ft_strjoin(s_str,buffer);
       
    }
    return (s_str);
}

char*   get_than_line(char* s_str)
{
    int len;
    char* Buffer;

    len = 0;
    while (s_str[len] != 0 && s_str[len] != '\n')
        len++;
    Buffer = malloc(sizeof(char) + (len + 2));
    if(!Buffer)
        return (NULL);
    len = 0;
    while (s_str[len] != 0 && s_str[len] != '\n')
    {
        Buffer[len] = s_str[len];
        len++;
    }
    if (s_str[len] == '\n')
    {
        Buffer[len] = '\n';
        Buffer[len + 1] = '\0';
    }
    else
        Buffer[len] = '\0';
    return (Buffer);
}

char* get_remminder(char* s_str)
{
    int len;
    int i;
    char* Buffer;

    len = 0;
    i   = 0;
    while (s_str[len] != '\0' && s_str[len] != '\n')
        len++;
    Buffer = malloc(sizeof(char) + ((ft_strlen(s_str) - len) + 1));
    if(!Buffer)
        return (NULL);
    len++;
    while (s_str[len] != '\0')
    {
        Buffer[i] = s_str[len];
        i++;
        len++;
    }
    Buffer[i] = '\0';
    return (Buffer);
}

char* get_next_line(int fd)
{
    static char* s_str;
    char*        r_str;

    r_str = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    s_str = get_read_str(fd, s_str);
    if (!s_str)
        return (NULL);
    r_str = get_than_line(s_str);
    if(!r_str)
        return(NULL);
    s_str = get_remminder(s_str);
    if (!s_str)
        return(NULL);
    return (r_str);

}

int main()
{

    int fd = open("text.txt", O_RDWR, 0644);

    char *BUFFER = get_next_line(fd);
    char *BU = get_next_line(fd);
     
    printf("--> %s\n", BUFFER);
    printf("--> %s\n",BU);

  

}
