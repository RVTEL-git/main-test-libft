#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

int	del_count = 0;

void	simple_del(void *content)
{
	if (content)
	{
		free(content);
		del_count++;
	}
}

void	test_lstclear(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = strdup("one");
	s2 = strdup("two");
	s3 = strdup("three");

	n1 = ft_lstnew(s1);
	n2 = ft_lstnew(s2);
	n3 = ft_lstnew(s3);
	n1->next = n2;
	n2->next = n3;

	ft_lstclear(&n1, simple_del);

	if (n1 == NULL && del_count == 3)
		printf("[OK]  list cleared, del called 3 times\n");
	else
	{
		printf("[KO]  list not fully cleared\n");
		printf("      n1 = %p | del_count = %d (expected 3)\n", (void *)n1, del_count);
	}
}

int	main(void)
{
	test_lstclear();
	return (0);
}