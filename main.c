#include "get_next_line.h"

int	main(void)
{
	int fd = open("text.txt", O_RDWR, 0644);

	printf("--> %s\n", get_next_line(fd));
	printf("--> %s\n", get_next_line(fd));
	printf("--> %s\n", get_next_line(fd));
	printf("--> %s\n", get_next_line(fd));
	printf("--> %s\n", get_next_line(fd));
}