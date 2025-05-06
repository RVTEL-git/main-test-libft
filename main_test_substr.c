#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(const char *s, unsigned int start, size_t len)
{
	char *r_ft = ft_substr(s, start, len);
	printf("s: \"%s\" | start: %u | len: %zu => \"%s\"\n", s, start, len, r_ft);
	free(r_ft);
}

int	main(void)
{
	test("Hello, world!", 0, 5);
	test("Hello, world!", 7, 5);
	test("Hello", 10, 3);
	test("42", 0, 0);
	test("substr", 3, 10);
	test("", 0, 1);
	test("abcdef", 2, 0);
	test("abcdef", 2, 3);
	return (0);
}
