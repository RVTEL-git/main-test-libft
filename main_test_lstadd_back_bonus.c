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

void	test_lstadd_back(void)
{
	t_list	*head;
	t_list	*new1;
	t_list	*new2;

	head = ft_lstnew("start");
	new1 = ft_lstnew("middle");
	new2 = ft_lstnew("end");
	ft_lstadd_back(&head, new1);
	ft_lstadd_back(&head, new2);
	t_list *last = ft_lstlast(head);
	if (last && last->content == (void *)"end")
	{
		printf("[OK]  last = %s\n", (char *)last->content);
	}
	else
	{
		printf("[KO]  Expected last = \"end\", got %s\n",
			last ? (char *)last->content : "NULL");
	}
	t_list *empty = NULL;
	t_list *first = ft_lstnew("only");

	ft_lstadd_back(&empty, first);

	if (empty == first && empty->next == NULL && empty->content == (void *)"only")
	{
		printf("[OK]  list created from NULL, content = %s\n", (char *)empty->content);
	}
	else
	{
		printf("[KO]  Failed to create list from NULL\n");
		if (empty)
			printf("      content = %s | next = %p\n",
				(char *)empty->content, (void *)empty->next);
		else
			printf("      list == NULL\n");
	}
	free(new2);
	free(new1);
	free(head);
	free(first);
}

int	main(void)
{
	test_lstadd_back();
	return (0);
}