#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "libft.h"

void	test(const char *src, size_t size)
{
	char dst1[50];
	char dst2[50];

	memset(dst1, 'X', sizeof(dst1));
	memset(dst2, 'X', sizeof(dst2));

	size_t r_std = strlcpy(dst1, src, size);
	size_t r_ft = ft_strlcpy(dst2, src, size);

	if (r_std == r_ft && strcmp(dst1, dst2) == 0)
		printf("[OK]     \"%s\" | size: %zu => \"%s\" (%zu)\n", src, size, dst2, r_ft);
	else
		printf("[KO]     \"%s\" | size: %zu => ft: \"%s\" (%zu) | std: \"%s\" (%zu)\n",
			src, size, dst2, r_ft, dst1, r_std);
}

int	main(void)
{
	test("hello", 10);
	test("hello", 5);
	test("hello", 3);
	test("", 5);
	test("longerstring", 0);
	test("copy", 1);
	test("copy", 2);
	test("copy", 50);
	test("a", 2);

	return (0);
}