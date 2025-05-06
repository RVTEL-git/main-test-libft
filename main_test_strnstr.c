#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "libft.h"

void	test(const char *haystack, const char *needle, size_t len)
{
	char *res_std = strnstr(haystack, needle, len);
	char *res_ft = ft_strnstr(haystack, needle, len);

	if (res_std == res_ft)
		printf("[OK]     \"%s\" in \"%s\" | len: %zu => \"%s\"\n",
			needle, haystack, len, res_ft ? res_ft : "NULL");
	else
		printf("[KO]     \"%s\" in \"%s\" | len: %zu => ft: \"%s\" | std: \"%s\"\n",
			needle, haystack, len,
			res_ft ? res_ft : "NULL",
			res_std ? res_std : "NULL");
}

int	main(void)
{
	test("hello world", "world", 11);
	test("hello world", "world", 5);
	test("42 network", "net", 10);
	test("abcdef", "", 6);
	test("", "", 1);
	test("", "a", 1);
	test("a", "a", 1);
	test("abc", "d", 3);
	test("abcabcabc", "cab", 9);
	test("abcabcabc", "cab", 4);
	test("abcabcabc", "abc", 2);

	return (0);
}