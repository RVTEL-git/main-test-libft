#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void test_calloc(size_t count, size_t size)
{
	void *std = calloc(count, size);
	void *ft = ft_calloc(count, size);

	if (!std && !ft)
	{
		printf("[OK] count = %zu, size = %zu (both NULL)\n", count, size);
		return;
	}
	if (!std || !ft)
	{
		printf("[KO] count = %zu, size = %zu (NULL mismatch)\n", count, size);
		free(std);
		free(ft);
		return;
	}

	int cmp = memcmp(std, ft, count * size);
	if (cmp == 0)
		printf("[OK] count = %zu, size = %zu\n", count, size);
	else
		printf("[KO] count = %zu, size = %zu (different content)\n", count, size);

	free(std);
	free(ft);
}

int main(void)
{
	test_calloc(0, 0);
	test_calloc(0, 10);
	test_calloc(10, 0);
	test_calloc(1, 1);
	test_calloc(4, 4);
	test_calloc(100, 1);
	test_calloc(1024, 4);
	test_calloc(SIZE_MAX, 2); // overflow
	test_calloc(2, SIZE_MAX); // overflow
	return 0;
}
