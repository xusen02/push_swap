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

int	push_swap(int argc, char **argv, t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
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
	adaptive_sort(stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(&stack_b);
	return (0);
}
