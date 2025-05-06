#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	increment_char(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

void	test(const char *s, char (*f)(unsigned int, char), const char *label)
{
	char *result = ft_strmapi(s, f);
	if (result)
		printf("[OK]     %s | input: \"%s\" => \"%s\"\n", label, s, result);
	else
		printf("[KO]     %s | input: \"%s\" => NULL\n", label, s);
	free(result);
}

int	main(void)
{
	test("abcdef", to_upper_even, "upper even");
	test("hello world", to_upper_even, "upper even");
	test("12345", increment_char, "increment");
	test("", to_upper_even, "empty");
	test("AaZz", increment_char, "increment");

	return (0);
}