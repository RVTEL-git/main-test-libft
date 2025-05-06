#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(const char *s)
{
	size_t r_std = strlen(s);
	size_t r_ft = ft_strlen(s);

	if (r_std == r_ft)
		printf("[OK]     \"%s\" => %zu\n", s, r_ft);
	else
		printf("[KO]     \"%s\" => ft_strlen: %zu | strlen: %zu\n", s, r_ft, r_std);
}

int	main(void)
{
	test("");
	test("a");
	test("42");
	test("hello");
	test("hello world");
	test("     ");
	test("this is a longer test string");
	test("test\0hidden");
	test("😀");
	test("end");

	return (0);
}