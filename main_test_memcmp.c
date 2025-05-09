#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_memcmp(const void *s1, const void *s2, size_t n)
{
	int	std = memcmp(s1, s2, n);
	int	ft = ft_memcmp(s1, s2, n);

	if ((std == 0 && ft == 0) || (std < 0 && ft < 0) || (std > 0 && ft > 0))
	{
		printf("[OK]  \"%s\" vs \"%s\", n = %zu => %d\n",
			(const char *)s1, (const char *)s2, n, ft);
	}
	else
	{
		printf("[KO]  \"%s\" vs \"%s\", n = %zu\n",
			(const char *)s1, (const char *)s2, n);
		printf("      std = %d\n", std);
		printf("      ft  = %d\n", ft);
	}
}

int	main(void)
{
	test_memcmp("abc", "abc", 3);
	test_memcmp("abc", "abd", 3);
	test_memcmp("abc", "abc", 0);
	test_memcmp("abcdef", "abcxyz", 3);
	test_memcmp("abcdef", "abcxyz", 6);
	test_memcmp("abcd", "abcz", 4);
	test_memcmp("123", "124", 3);
	test_memcmp("same", "same", 10);
	test_memcmp("short", "shorter", 5);
	test_memcmp("shorter", "short", 5);
	test_memcmp("", "", 1);
	return (0);
}