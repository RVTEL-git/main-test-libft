#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void test_isalpha(int c)
{
	int std = isalpha(c);
	int ft = ft_isalpha(c);

	if ((std && ft) || (!std && !ft))
		printf("[OK]  '%c' (%d) => %d\n", (c >= 32 && c <= 126 ? c : '.'), c, ft);
	else
		printf("[KO]  '%c' (%d) => ft: %d | std: %d\n", (c >= 32 && c <= 126 ? c : '.'), c, ft, std);
}

int main(void)
{
	for (int i = -10; i <= 130; i++)
		test_isalpha(i);
	return 0;
}
