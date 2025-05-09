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

void	append_x(void *content)
{
	char	*str = (char *)content;
	size_t	len = strlen(str);

	if (len < 99)
		str[len] = 'x';
}

void	test_lstiter(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = malloc(100);
	s2 = malloc(100);
	s3 = malloc(100);
	if (!s1 || !s2 || !s3)
	{
		printf("[KO]  malloc failed\n");
		return ;
	}

	strcpy(s1, "one");
	strcpy(s2, "two");
	strcpy(s3, "three");

	n1 = ft_lstnew(s1);
	n2 = ft_lstnew(s2);
	n3 = ft_lstnew(s3);
	n1->next = n2;
	n2->next = n3;

	ft_lstiter(n1, append_x);

	if (strcmp(s1, "onex") == 0 &&
		strcmp(s2, "twox") == 0 &&
		strcmp(s3, "threex") == 0)
		printf("[OK]  all elements modified correctly\n");
	else
	{
		printf("[KO]  wrong content after iteration\n");
		printf("      s1 = %s\n", s1);
		printf("      s2 = %s\n", s2);
		printf("      s3 = %s\n", s3);
	}

	free(s1);
	free(s2);
	free(s3);
}

int	main(void)
{
	test_lstiter();
	return (0);
}