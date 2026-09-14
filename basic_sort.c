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

void sort_three(t_node **stack_a)
{
    int max;

    if (is_sorted(*stack_a))
        return ;
    max = find_max(*stack_a);
    if ((*stack_a)->nbr == max)
        ra(stack_a);
    else if ((*stack_a)->down->nbr == max)
        rra(stack_a);
    if ((*stack_a)->nbr > (*stack_a)->down->nbr)
        sa(stack_a);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
    int min_index;
    int size;
    int rra_count;

    while (get_stack_size(*stack_a) > 3)
    {
        min_index = find_min_index(*stack_a);
        size = get_stack_size(*stack_a);
        if (min_index <= size /2)
        {
            while (min_index--) 
                ra(stack_a);
        }
        else
        {
            rra_count = size - min_index;
            while (rra_count--)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}
