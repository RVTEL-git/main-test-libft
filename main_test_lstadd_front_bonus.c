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

void	test_lstadd_front(void)
{
	t_list	*head;
	t_list	*new;

	head = ft_lstnew("two");
	new = ft_lstnew("one");

	ft_lstadd_front(&head, new);

	if (head == new
		&& head->content == (void *)"one"
		&& head->next != NULL
		&& head->next->content == (void *)"two")
	{
		printf("[OK]  head = \"%s\" -> \"%s\"\n",
			(char *)head->content,
			(char *)head->next->content);
	}
	else
	{
		printf("[KO]  Expected list: \"one\" -> \"two\"\n");
		if (head != new)
			printf("      head != new\n");
		if (head)
		{
			printf("      head->content = %s\n",
				head->content ? (char *)head->content : "NULL");
			printf("      head->next = %p\n", (void *)head->next);
			if (head->next)
				printf("      head->next->content = %s\n",
					(char *)head->next->content);
		}
		else
			printf("      head == NULL\n");
	}

	free(head->next);
	free(head);
}

int	main(void)
{
	test_lstadd_front();
	return (0);
}
