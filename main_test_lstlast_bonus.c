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

void	test_lstlast(t_list *start, const char *expected)
{
	t_list	*last = ft_lstlast(start);

	if ((last == NULL && expected == NULL)
		|| (last && last->content == (void *)expected))
	{
		printf("[OK]  last = %s\n", last ? (char *)last->content : "NULL");
	}
	else
	{
		printf("[KO]  Expected last = %s, got %s\n",
			expected ? expected : "NULL",
			last ? (char *)last->content : "NULL");
	}
}

int	main(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	n1 = ft_lstnew("first");
	n2 = ft_lstnew("middle");
	n3 = ft_lstnew("last");

	n1->next = n2;
	n2->next = n3;

	test_lstlast(n1, "last");
	test_lstlast(n2, "last");
	test_lstlast(n3, "last");
	test_lstlast(NULL, NULL);

	free(n3);
	free(n2);
	free(n1);
	return (0);
}