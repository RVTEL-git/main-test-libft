#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(const void *src, size_t n)
{
	char	dest1[100] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char	dest2[100] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

	memcpy(dest1, src, n);
	ft_memcpy(dest2, src, n);

	if (memcmp(dest1, dest2, n) == 0)
		printf("[OK]     src: \"%s\" | n: %zu => \"%s\"\n", (const char *)src, n, dest2);
	else
		printf("[KO]     src: \"%s\" | n: %zu => ft_memcpy: \"%s\" | memcpy: \"%s\"\n",
			(const char *)src, n, dest2, dest1);
}

int	main(void)
{
	test("Hello", 5);
	test("Hello", 0);
	test("Hello", 1);
	test("Hello", 3);
	test("", 0);
	test("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26);
	test("42", 2);
	test("42", 1);
	test("Same length", 11);
	test("Short", 10);
	test("Overlap", 7);
	
	return (0);
}
