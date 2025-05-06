#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	test(int c)
{
	int std = toupper(c);
	int ft = ft_toupper(c);

	if (std == ft)
		printf("[OK]     input: '%c' (%d) => %d\n", c, c, ft);
	else
		printf("[KO]     input: '%c' (%d) => ft_toupper: %d | toupper: %d\n", c, c, ft, std);
}

int	main(void)
{
	test('a');
	test('z');
	test('A');
	test('Z');
	test('0');
	test('@');
	test('[');
	test('~');
	test(200);
	test(-5);
	return (0);
}