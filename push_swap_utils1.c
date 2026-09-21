/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:20 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/02 15:33:23 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_single_arg(char *arg, t_node **stack_a)
{
	int		nbr;
	t_node	*new_node;

	if (!is_valid(arg))
	{
		free_stack(stack_a);
		return (1);
	}
	nbr = ft_atoi(arg);
	if (repeat_nbr(*stack_a, nbr))
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
	return (0);
}

int	in_nbr(int argc, char **argv, t_node **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (process_single_arg(argv[i], stack_a))
			return (1);
		i++;
	}
	return (0);
}

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->down;
	}
	return (size);
}

void	normalize_index(t_node **stack)
{
	t_node	*curr;
	t_node	*compare;
	int		index;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr != NULL)
	{
		compare = *stack;
		index = 0;
		while (compare != NULL)
		{
			if (curr->nbr > compare->nbr)
				index++;
			compare = compare->down;
		}
		curr->index = index;
		curr = curr->down;
	}
}

double	compute_disorder(t_node **stack_a)
{
	double	error;
	double	pairs;
	t_node	*current;
	t_node	*compare;

	error = 0;
	pairs = 0;
	current = *stack_a;
	while (current)
	{
		compare = current->down;
		while (compare)
		{
			pairs++;
			if (current->nbr > compare->nbr)
				error++;
			compare = compare->down;
		}
		current = current->down;
	}
	return (error / pairs);
}
