#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	print_split(char **tab)
{
	int	i = 0;

	while (tab && tab[i])
	{
		printf("  [%d] \"%s\"\n", i, tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	test(const char *s, char c)
{
	printf("Input: \"%s\" | sep: '%c'\n", s, c);
	char **result = ft_split(s, c);
	if (result)
		print_split(result);
	else
		printf("  [KO] => NULL\n");
}

int	main(void)
{
	test("hello world test", ' ');
	test("   split  this please  ", ' ');
	test("42", ' ');
	test("abc,,def,,ghi", ',');
	test("", ',');
	test(",,,,", ',');
	test("no-separators", ' ');
	test("a b c", ' ');
	test("a  b  c", ' ');
	test(" multiple   spaces ", ' ');
	test("start-and-end-", '-');
	test("-start-and-end-", '-');
	test("oneword", '-');

	return (0);
}