#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	test(int c)
{
	int std = tolower(c);
	int ft = ft_tolower(c);

	if (std == ft)
		printf("[OK]     input: '%c' (%d) => %d\n", c, c, ft);
	else
		printf("[KO]     input: '%c' (%d) => ft_tolower: %d | tolower: %d\n", c, c, ft, std);
}

int	main(void)
{
	test('A');
	test('Z');
	test('a');
	test('z');
	test('0');
	test('@');
	test('[');
	test('~');
	test(200);
	test(-5);
	return (0);
}