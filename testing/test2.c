#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	char *line = av[1];
	if (line)
		printf("line is: {%s}\n", line);
	else if (!line)
		printf("line is null: {%s}\n", line);
	return (0);
}
