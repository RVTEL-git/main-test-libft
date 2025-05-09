
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	test_lstnew(void *content)
{
	t_list	*node = ft_lstnew(content);

	if (node != NULL && node->content == content && node->next == NULL)
	{
		printf("[OK]  content = %s | next = %s\n",
			(content ? (char *)content : "NULL"), "NULL");
	}
	else
	{
		printf("[KO]  content = %s\n", content ? (char *)content : "NULL");
		if (node == NULL)
			printf("      node == NULL\n");
		else
		{
			printf("      node->content = %s\n", node->content ? (char *)node->content : "NULL");
			printf("      node->next = %p\n", node->next);
		}
	}

	free(node);
}

int	main(void)
{
	test_lstnew("hello");
	test_lstnew("42");
	test_lstnew("");
	test_lstnew(NULL);
	return (0);
}