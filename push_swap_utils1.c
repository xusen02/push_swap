#include "push_swap.h"

int	store_in(t_node *new_node, t_node **tung_tung)
{
	t_node	*last;

	if (!*tung_tung)
	{
		*tung_tung = new_node;
		new_node->up = NULL;
	}
	else
	{
		last = *tung_tung;
		while (last->down)
			last = last->down;
		last->down = new_node;
		new_node->up = last;
	}
	return (0);
}

int	in_nbr(int argc, char **argv, t_node **stack_a)
{
	int		i;
	int		nbr;
	t_node	*new_node;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (!is_valid(argv[i]) || repeat_nbr(*stack_a, nbr))
		{
			free_stack(stack_a);
			return (1);
		}
		new_node = create_node(nbr);
		if (!new_node)
		{
			free_stack(stack_a);
			return (1);
		}
		store_in(new_node, stack_a);
		i++;
	}
	return (0);
}

int get_stack_size(t_node *stack)
{
    int     size;

    size = 0;
    while (stack)
    {
        size ++;
        stack = stack->down;
    }
    return (size);
}

int pick_swap(t_node **stack_a, t_node **stack_b)
{
    int size;

    if (!stack_a || !*stack_a)
        return (0);
    size = get_stack_size(*stack_a);
    if (size == 1)
        return (1);
    else if (size == 2 && (*stack_a)->nbr > (*stack_a)->down->nbr)
        sa(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size <= 5)
        sort_five(stack_a, stack_b);
	else
		chunks_sort(stack_a, stack_b);
    return (1);
}