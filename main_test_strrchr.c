#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(const char *s, int c)
{
	char *res_std = strrchr(s, c);
	char *res_ft = ft_strrchr(s, c);

	if (res_std == res_ft)
		printf("[OK]     \"%s\" | '%c' => \"%s\"\n", s, c, res_ft ? res_ft : "NULL");
	else
		printf("[KO]     \"%s\" | '%c' => ft: \"%s\" | std: \"%s\"\n",
			s, c,
			res_ft ? res_ft : "NULL",
			res_std ? res_std : "NULL");
}

int	main(void)
{
	test("hello world", 'l');
	test("hello world", 'h');
	test("hello world", 'd');
	test("hello world", '\0');
	test("hello world", 'z');
	test("", 'a');
	test("", '\0');
	test("abcabcabc", 'b');
	test("abcabcabc", 'c');
	test("abcabcabc", 'x');

	return (0);
}