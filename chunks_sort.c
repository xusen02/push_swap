/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:04:48 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/07 13:04:50 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (35);
}

static void	final_rotate_a(t_node **stack_a, t_bench *bench)
{
	int	min_pos;
	int	size_a;

	size_a = get_stack_size(*stack_a);
	min_pos = find_min_index(*stack_a);
	if (min_pos <= size_a / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, bench);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size_a)
		{
			rra(stack_a, bench);
			min_pos++;
		}
	}
}

static void	push_back_to_a(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	max_pos;
	int	size_b;

	while (*stack_b != NULL)
	{
		size_b = get_stack_size(*stack_b);
		max_pos = find_max_index(*stack_b);
		if (max_pos <= size_b / 2)
		{
			while (max_pos > 0)
			{
				rb(stack_b, bench);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size_b)
			{
				rrb(stack_b, bench);
				max_pos++;
			}
		}
		pa(stack_a, stack_b, bench);
	}
}

void	chunks_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;
	int	chunk_size;
	int	min;
	int	max;

	size = get_stack_size(*stack_a);
	chunk_size = get_chunk_size(size);
	min = 0;
	max = chunk_size;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index < max)
		{
			pb(stack_a, stack_b, bench);
			if ((*stack_b)->index < (min + max) / 2)
				rb(stack_b, bench);
			min++;
			max++;
		}
		else
			ra(stack_a, bench);
	}
	push_back_to_a(stack_a, stack_b, bench);
	final_rotate_a(stack_a, bench);
}
