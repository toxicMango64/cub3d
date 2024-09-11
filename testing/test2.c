#include "test.h"

int main(int ac, char **av)
{
	if (2 != ac)
		return (usage_msg(av));
	return (EXIT_SUCCESS);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	char *line = av[1];
// 	if (line)
// 		printf("line is: {%s}\n", line);
// 	else if (!line)
// 		printf("line is null: {%s}\n", line);
// 	return (0);
// }
