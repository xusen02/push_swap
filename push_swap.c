/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:07:56 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/01 12:08:01 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_match(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (s1[i] == s2[i]);
}

static int	get_sort_type(int *argc, char ***argv)
{
	if (*argc <= 1)
		return (0);
	if (is_match((*argv)[1], "simple"))
	{
		(*argv)++;
		(*argc)--;
		return (1);
	}
	if (is_match((*argv)[1], "medium"))
	{
		(*argv)++;
		(*argc)--;
		return (2);
	}
	if (is_match((*argv)[1], "complex"))
	{
		(*argv)++;
		(*argc)--;
		return (3);
	}
	return (0);
}

static void	execute_sort(int sort_type, t_node **stack_a, t_node **stack_b)
{
	if (sort_type == 1)
		selection_sort(stack_a, stack_b);
	else if (sort_type == 2)
		chunks_sort(stack_a, stack_b);
	else if (sort_type == 3)
		radix_sort(stack_a, stack_b);
	else
		adaptive_sort(stack_a, stack_b);
}

int	push_swap(int argc, char **argv, t_node **stack_a)
{
	t_node	*stack_b;
	int		sort_type;

	stack_b = NULL;
	sort_type = get_sort_type(&argc, &argv);
	if (in_nbr(argc, argv, stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(*stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	normalize_index(stack_a);
	execute_sort(sort_type, stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(&stack_b);
	return (0);
}
