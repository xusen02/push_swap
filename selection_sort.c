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

void selection_sort(t_node **a, t_node **b)
{
    int size;
    int min_pos;

    size = get_stack_size(*a);
    while (size > 3)
    {
        min_pos = find_min_index(*a);
        if (min_pos <= size / 2)
        {
            while (min_pos > 0)
            {
                ra(a);
                min_pos--;
            }
        }
        else
        {
            while (min_pos < size)
            {
                rra(a);
                min_pos++;
            }
        }
        pb(a, b);
        size--;
    }
    sort_three(a);
    while (*b)
        pa(a, b);
}