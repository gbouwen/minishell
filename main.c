#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int		status;
	char	*line;

	status = 1;
	while (status)
	{
		write(1, "> ", 2);
		get_next_line(0, &line);
		printf("%s\n", line);
	}
	return (0);
}
