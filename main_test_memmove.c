#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(const char *src_init, size_t n, size_t dst_offset)
{
	char	buf1[100] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	char	buf2[100] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

	strcpy(buf1 + dst_offset, src_init);
	strcpy(buf2 + dst_offset, src_init);

	memmove(buf1 + dst_offset, buf1, n);
	ft_memmove(buf2 + dst_offset, buf2, n);

	if (memcmp(buf1, buf2, n + dst_offset) == 0)
		printf("[OK]     src: \"%s\" | n: %zu | offset: %zu => \"%s\"\n", src_init, n, dst_offset, buf2);
	else
		printf("[KO]     src: \"%s\" | n: %zu | offset: %zu => ft_memmove: \"%s\" | memmove: \"%s\"\n",
			src_init, n, dst_offset, buf2, buf1);
}

int	main(void)
{
	test("HelloWorld", 5, 0);
	test("HelloWorld", 5, 2);
	test("HelloWorld", 0, 3);
	test("OverlapTest", 10, 5);
	test("ABCDEF", 6, 3);
	test("123456789", 9, 1);
	test("42", 2, 0);
	test("Lorem ipsum", 11, 6);

	return (0);
}
