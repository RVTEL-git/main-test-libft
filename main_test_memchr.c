#include <stdio.h>
#include <string.h>
#include "libft.h"

void test_memchr(const void *s, int c, size_t n)
{
	void *std = memchr(s, c, n);
	void *ft = ft_memchr(s, c, n);

	if (std == ft)
		printf("[OK]  \"%s\", c = %d ('%c'), n = %zu => %s\n",
			(const char *)s, c, (c >= 32 && c <= 126 ? c : '.'), n,
			(std ? (char *)std : "NULL"));
	else
	{
		printf("[KO]  \"%s\", c = %d ('%c'), n = %zu\n", 
			(const char *)s, c, (c >= 32 && c <= 126 ? c : '.'), n);
		printf("      std = %s\n", std ? (char *)std : "NULL");
		printf("      ft  = %s\n", ft ? (char *)ft : "NULL");
	}
}

int main(void)
{
	const char *s = "Hello World!";
	test_memchr(s, 'H', 12);
	test_memchr(s, 'W', 12);
	test_memchr(s, 'o', 5);
	test_memchr(s, 'o', 0);
	test_memchr(s, '!', 12);
	test_memchr(s, 'x', 12);
	test_memchr(s, 0, 12);
	test_memchr("", 'a', 1);
	test_memchr("abc\0def", '\0', 7);
	return 0;
}
