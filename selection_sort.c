/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 16:50:00 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/09 16:50:00 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_min(t_node **a, int size, t_bench *bench)
{
	int	min_pos;

	min_pos = find_min_index(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, bench);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a, bench);
			min_pos++;
		}
	}
}

void	selection_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	size = get_stack_size(*a);
	while (size > 3)
	{
		rotate_to_min(a, size, bench);
		pb(a, b, bench);
		size--;
	}
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}
