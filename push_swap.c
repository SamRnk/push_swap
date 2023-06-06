#include	<stdio.h>
#include	<stdlib.h>

int	ft_atoi(const char *str);

typedef struct s_push
{
	int		n;
	struct s_push	*next;
}	t_push;

t_push	*make_list(int nbr, t_push *last_node)
{
	t_push	*new_node;

	new_node = malloc(sizeof(t_push));
	if (!new_node)
		return (NULL);
	new_node->n = nbr;
	new_node->next = NULL;
	if (last_node != NULL)
		last_node->next = new_node;
	return (new_node);
}

int	main(int argc, char *argv[])
{
	int	i;
	t_push	*head;
	t_push	*last_node;

	i = 2;
	head = make_list(ft_atoi(argv[1]), NULL);
	last_node = head;
	while (argv[i])
	{
		last_node = make_list(ft_atoi(argv[i]), last_node);
		i++;
	}
	free(last_node);
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	return (0);
}
