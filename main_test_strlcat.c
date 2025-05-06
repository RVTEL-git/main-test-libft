#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "libft.h"

void	test(const char *src, size_t size)
{
	char dst1[50] = "12345";
	char dst2[50] = "12345";

	size_t r_std = strlcat(dst1, src, size);
	size_t r_ft = ft_strlcat(dst2, src, size);

	if (r_std == r_ft && strcmp(dst1, dst2) == 0)
		printf("[OK]     dst: \"12345\" + \"%s\" | size: %zu => \"%s\" (%zu)\n", src, size, dst2, r_ft);
	else
		printf("[KO]     dst: \"12345\" + \"%s\" | size: %zu => ft: \"%s\" (%zu) | std: \"%s\" (%zu)\n",
			src, size, dst2, r_ft, dst1, r_std);
}

int	main(void)
{
	test("abc", 10);
	test("abc", 5);
	test("abc", 8);
	test("", 5);
	test("longerstring", 0);
	test("longerstring", 3);
	test("moretext", 50);
	test("another", 7);
	test("A", 6);

	return (0);
}
