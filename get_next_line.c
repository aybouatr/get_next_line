#include "get_next_line.h"


char*   get_next_line(int fd)
{
    s_list *list;
    static char* s_str;
    int check;

    s_str = NULL;
    check = 1;
    list = ft_lstnew();
    if (fd < 0)
        return (0);
    while (check)
    {
        list->BUFFER = malloc(BUFFER_SIZE * sizeof(char ));
        if (!list->BUFFER)
            return (free_all_alcoted());
        if(-1 == read(fd,list->BUFFER,BUFFER_SIZE) || get_new_line(list->BUFFER))
            break;
        list->next = ft_lstnew();
    }
    return ();
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