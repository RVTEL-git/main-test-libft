#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	test_lstsize(t_list *start, int expected)
{
	int	result = ft_lstsize(start);

	if (result == expected)
	{
		printf("[OK]  size = %d\n", result);
	}
	else
	{
		printf("[KO]  Expected size = %d, got %d\n", expected, result);
	}
}

int	main(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	n1 = ft_lstnew("one");
	n2 = ft_lstnew("two");
	n3 = ft_lstnew("three");

	n1->next = n2;
	n2->next = n3;

	test_lstsize(n1, 3);
	test_lstsize(n2, 2);
	test_lstsize(n3, 1);
	test_lstsize(NULL, 0);

	free(n3);
	free(n2);
	free(n1);
	return (0);
}