#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *curr;

	curr = lst;
	if (curr == NULL)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

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

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *curr;

	if (!lst || !*lst || !del)
			return ;
	while (*lst != NULL)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = curr;
	}
	*lst = NULL;
}


void	*strdup_and_upper(void *content)
{
	char	*src = (char *)content;
	char	*copy = strdup(src);
	int		i = 0;

	if (!copy)
		return (NULL);
	while (copy[i])
	{
		if (copy[i] >= 'a' && copy[i] <= 'z')
			copy[i] -= 32;
		i++;
	}
	return (copy);
}

void	simple_del(void *content)
{
	free(content);
}

void	test_lstmap(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*new;
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

	new = ft_lstmap(n1, strdup_and_upper, simple_del);

	if (new
		&& strcmp((char *)new->content, "ONE") == 0
		&& strcmp((char *)new->next->content, "TWO") == 0
		&& strcmp((char *)new->next->next->content, "THREE") == 0)
	{
		printf("[OK]  map successful, all values transformed\n");
	}
	else
	{
		printf("[KO]  mapping failed or incorrect values\n");
		if (new)
		{
			printf("      new->content: %s\n", (char *)new->content);
			printf("      new->next->content: %s\n", (char *)new->next->content);
			printf("      new->next->next->content: %s\n", (char *)new->next->next->content);
		}
		else
			printf("      new is NULL\n");
	}

	// Clean memory
	ft_lstclear(&n1, simple_del);
	ft_lstclear(&new, simple_del);
}

int	main(void)
{
	test_lstmap();
	return (0);
}