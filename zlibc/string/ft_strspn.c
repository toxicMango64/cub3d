#include <stdio.h>
#include <string.h>
#include <unistd.h>
# define WHITESPACE	"\v \t\f\r\n"
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

int main(int ac, char **av)
{
	if (2 > ac)
		return (printf("invalid amount of args\n"), EXIT_FAILURE);

	char *s1 = av[1];
	size_t i = strspn(s1, WHITESPACE);

	printf("sizeof s1:{%zu}:{%s}, {%zu}\n", strlen(s1), s1, i);

	return (EXIT_SUCCESS);
}
