#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	test(const char *s1, const char *s2)
{
	char *result = ft_strjoin(s1, s2);
	if (result)
		printf("[OK]     \"%s\" + \"%s\" => \"%s\"\n", s1, s2, result);
	else
		printf("[KO]     \"%s\" + \"%s\" => NULL\n", s1, s2);
	free(result);
}

int	main(void)
{
	test("Hello", "World");
	test("", "World");
	test("Hello", "");
	test("", "");
	test("42", "Network");
	test("Libft", "Test");
	test("Concat", "enation");
	test("Special ", "#!@");
	test("Long string ", "with another long string");

	return (0);
}
