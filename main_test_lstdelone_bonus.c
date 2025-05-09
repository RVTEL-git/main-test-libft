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

int	del_called = 0;

void	simple_del(void *content)
{
	if (content)
	{
		del_called = 1;
		free(content);
	}
}

void	test_lstdelone(void)
{
	t_list	*node;
	char	*data;

	data = malloc(10);
	if (!data)
	{
		printf("[KO]  malloc failed\n");
		return ;
	}
	strcpy(data, "delete me");

	node = ft_lstnew(data);

	ft_lstdelone(node, simple_del);

	if (del_called)
		printf("[OK]  del() called and content freed\n");
	else
		printf("[KO]  del() was not called\n");
}

int	main(void)
{
	test_lstdelone();
	return (0);
}