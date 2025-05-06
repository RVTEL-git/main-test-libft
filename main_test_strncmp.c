#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(const char *s1, const char *s2, size_t n)
{
	int r_std = strncmp(s1, s2, n);
	int r_ft = ft_strncmp(s1, s2, n);

	if ((r_std == 0 && r_ft == 0) || (r_std < 0 && r_ft < 0) || (r_std > 0 && r_ft > 0))
		printf("[OK]     \"%s\" vs \"%s\" | n: %zu => %d\n", s1, s2, n, r_ft);
	else
		printf("[KO]     \"%s\" vs \"%s\" | n: %zu => ft_strncmp: %d | strncmp: %d\n",
			s1, s2, n, r_ft, r_std);
}

int	main(void)
{
	test("abc", "abc", 3);
	test("abc", "abd", 3);
	test("abc", "abcde", 3);
	test("abcde", "abc", 5);
	test("abc", "ABC", 3);
	test("abc", "abc", 0);
	test("", "", 1);
	test("a", "", 1);
	test("", "a", 1);
	test("abcd", "abcf", 4);
	test("abcd", "abcf", 2);

	return (0);
}