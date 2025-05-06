#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "libft.h"

void print_buffer(const void *buf, size_t size)
{
	const unsigned char *b = buf;
	for (size_t i = 0; i < size; i++)
		printf("%02x ", b[i]);
	printf("\n");
}

void test_bzero(size_t size)
{
	char *std_buf = malloc(size);
	char *ft_buf = malloc(size);

	if (!std_buf || !ft_buf)
		return;

	memset(std_buf, 0x42, size);
	memset(ft_buf, 0x42, size);

	bzero(std_buf, size);
	ft_bzero(ft_buf, size);

	int cmp = memcmp(std_buf, ft_buf, size);

	if (cmp == 0)
		printf("[OK] size = %zu\n", size);
	else
	{
		printf("[KO] size = %zu\n", size);
		printf("bzero : "); print_buffer(std_buf, size);
		printf("ft    : "); print_buffer(ft_buf, size);
	}

	free(std_buf);
	free(ft_buf);
}

int main(void)
{
	test_bzero(0);
	test_bzero(1);
	test_bzero(2);
	test_bzero(5);
	test_bzero(10);
	test_bzero(100);
	test_bzero(1024);
	return (0);
}