#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(const char *s1, const char *set)
{
	char *r_ft = ft_strtrim(s1, set);

	printf("s1: \"%s\" | set: \"%s\" => \"%s\"\n", s1, set, r_ft);
	free(r_ft);
}

int	main(void)
{
	test("  Hello  ", " ");
	test("xx42xx", "x");
	test("abchelloabc", "abc");
	test("no_trim", "");
	test("", "abc");
	test("abc", "abc");
	test("   ", " ");
	test("abc", "xyz");
	test("  a b c  ", " ");
	return (0);
}