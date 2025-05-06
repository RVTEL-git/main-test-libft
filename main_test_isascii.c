#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void test_isascii(int c)
{
	int std = isascii(c);
	int ft = ft_isascii(c);

	if ((std && ft) || (!std && !ft))
		printf("[OK]  (%3d) => %d\n", c, ft);
	else
		printf("[KO]  (%3d) => ft: %d | std: %d\n", c, ft, std);
}

int main(void)
{
	for (int i = -10; i <= 140; i++)
		test_isascii(i);
	return 0;
}