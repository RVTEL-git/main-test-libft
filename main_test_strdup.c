#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	test(char *src)
{
	char *res_std = strdup(src);
	char *res_ft = ft_strdup(src);

	if (res_std && res_ft && strcmp(res_std, res_ft) == 0)
		printf("[OK]     \"%s\" => \"%s\"\n", src, res_ft);
	else if (!res_std && !res_ft)
		printf("[OK]     \"%s\" => NULL\n", src);
	else
		printf("[KO]     \"%s\" => ft_strdup: \"%s\" | strdup: \"%s\"\n",
			src,
			res_ft ? res_ft : "NULL",
			res_std ? res_std : "NULL");

	free(res_std);
	free(res_ft);
}

int	main(void)
{
	test("hello");
	test("");
	test("42");
	test("longer test string with spaces and symbols #!@");
	test("a");
	test("abcdefghijklmnopqrstuvwxyz");
	test("    ");
	test("test\0hidden");
	test("😀 unicode test");

	return (0);
}