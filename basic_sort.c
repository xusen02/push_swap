/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:04:48 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/07 13:04:50 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a, t_bench *bench)
{
	int	max;

	if (is_sorted(*stack_a))
		return ;
	max = find_max(*stack_a);
	if ((*stack_a)->nbr == max)
		ra(stack_a, bench);
	else if ((*stack_a)->down->nbr == max)
		rra(stack_a, bench);
	if ((*stack_a)->nbr > (*stack_a)->down->nbr)
		sa(stack_a, bench);
}

void	sort_five(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	min_index;
	int	size;
	int	rra_count;

	while (get_stack_size(*stack_a) > 3)
	{
		min_index = find_min_index(*stack_a);
		size = get_stack_size(*stack_a);
		if (min_index <= size / 2)
		{
			while (min_index--)
				ra(stack_a, bench);
		}
		else
		{
			rra_count = size - min_index;
			while (rra_count--)
				rra(stack_a, bench);
		}
		pb(stack_a, stack_b, bench);
	}
	sort_three(stack_a, bench);
	pa(stack_a, stack_b, bench);
	pa(stack_a, stack_b, bench);
}
