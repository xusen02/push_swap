/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:06:54 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/18 12:06:54 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_len_finder(int max)
{
	int	len;

	len = 0;
	while (max >> len)
		len++;
	return (len);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	max_bit_len;
	int	counter1;
	int	counter2;

	max_bit_len = bit_len_finder(get_stack_size(*a) - 1);
	counter1 = 0;
	while (counter1 < max_bit_len)
	{
		counter2 = get_stack_size(*a);
		while (counter2--)
		{
			if (((*a)->index >> counter1) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (get_stack_size(*b))
			pa(a, b);
		counter1++;
	}
}
