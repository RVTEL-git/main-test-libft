#include <stdio.h>
#include <string.h>
#include "libft.h"

void	to_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	increment_all(unsigned int i, char *c)
{
	(void)i;
	(*c)++;
}

void	test(char *str, void (*f)(unsigned int, char *), const char *label)
{
	char buffer[100];
	strcpy(buffer, str);
	ft_striteri(buffer, f);
	printf("[TEST] %s | input: \"%s\" => result: \"%s\"\n", label, str, buffer);
}

int	main(void)
{
	test("abcdef", to_upper_even, "upper even");
	test("hello world", to_upper_even, "upper even");
	test("12345", increment_all, "increment");
	test("", to_upper_even, "empty");
	test("AaZz", increment_all, "increment");

	return (0);
}