/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 16:50:00 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/09 16:50:00 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b(t_node **a, t_node **b, t_bench *bench, int total_size)
{
	int	i;
	int	chunk_size;

	i = 0;
	if (total_size <= 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
}

void	push_back_to_a(t_node **a, t_node **b, t_bench *bench)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		max_pos = find_max_index(*b);
		size = get_stack_size(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos > 0)
			{
				rb(b, bench);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size)
			{
				rrb(b, bench);
				max_pos++;
			}
		}
		pa(a, b, bench);
	}
}

void	insertion_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	size = get_stack_size(*a);
	if (size <= 1)
		return ;
	push_chunks_to_b(a, b, bench, size);
	push_back_to_a(a, b, bench);
}
