#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDWR, 0644);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	free(str);
}
