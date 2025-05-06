#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test(size_t len, int c)
{
	char	buf1[100] = "abcdefghijklmnopqrstuvwxyz";
	char	buf2[100] = "abcdefghijklmnopqrstuvwxyz";

	memset(buf1, c, len);
	ft_memset(buf2, c, len);

	if (memcmp(buf1, buf2, len) == 0)
		printf("[OK]     char: %d | len: %zu => \"%.*s\"\n", c, len, (int)len, buf2);
	else
		printf("[KO]     char: %d | len: %zu => ft_memset: \"%.*s\" | memset: \"%.*s\"\n",
			c, len, (int)len, buf2, (int)len, buf1);
}

int	main(void)
{
	test(0, 'A');
	test(5, 'A');
	test(10, 'B');
	test(26, 'Z');
	test(1, 0);
	test(15, 1);
	test(20, 255);
	test(30, 128);

	return (0);
}