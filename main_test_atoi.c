#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	test(const char *str)
{
	int	std_result = atoi(str);
	int	ft_result = ft_atoi(str);

	if (std_result == ft_result)
		printf("[OK]     \"%s\" => %d\n", str, ft_result);
	else
		printf("[KO]     \"%s\" => ft_atoi: %d | atoi: %d\n", str, ft_result, std_result);
}

int	main(void)
{
	test("0");
	test("42");
	test("-42");
	test("2147483647");
	test("-2147483648");

	test("   123");
	test("\t\n\r\v\f123");

	test("   +123");
	test("   -123");

	test("--123");
	test("++123");
	test("+-123");
	test("-+123");

	test("123abc");
	test("  -42truc");
	test(" +00123a");

	test("abc");
	test("");
	test("    ");
	test(" \n \t +");

	test("999999999999999999999999999");
	test("-999999999999999999999999999");

	test("+");
	test("-");
	test("+ 1");
	test("- 1");
	test("0000123");

	return (0);
}