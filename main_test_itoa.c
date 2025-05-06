#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

void test_itoa(int n)
{
    char std[12];
    char *ft = ft_itoa(n);

    snprintf(std, sizeof(std), "%d", n);

    if (ft && strcmp(ft, std) == 0)
        printf("[OK]  n = %d => \"%s\"\n", n, ft);
    else
        printf("[KO]  n = %d => ft: \"%s\" | std: \"%s\"\n", n, ft, std);

    free(ft);
}

int main(void)
{
	test_itoa(0);
	test_itoa(1);
	test_itoa(-1);
	test_itoa(42);
	test_itoa(-42);
	test_itoa(123456);
	test_itoa(-123456);
	test_itoa(INT_MAX);
	test_itoa(INT_MIN);
	test_itoa(1000000000);
	test_itoa(-1000000000);
	return 0;
}
