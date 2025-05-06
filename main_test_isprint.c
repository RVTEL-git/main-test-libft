#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void test_isprint(int c)
{
	int std = isprint(c);
	int ft = ft_isprint(c);

	if ((std && ft) || (!std && !ft))
		printf("[OK]  (%3d) '%c' => %d\n", c, (c >= 32 && c <= 126 ? c : '.'), ft);
	else
		printf("[KO]  (%3d) '%c' => ft: %d | std: %d\n", c, (c >= 32 && c <= 126 ? c : '.'), ft, std);
}

int main(void)
{
	for (int i = -10; i <= 140; i++)
		test_isprint(i);
	return 0;
}
