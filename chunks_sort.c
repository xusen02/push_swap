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

static int get_bucket_size(int size)
{
	if (size <= 100)
		return (20);
	if (size <= 500)
		return (40);
	return (5);
}

static void push_back_to_a(t_node **stack_a, t_node **stack_b)
{
    int     target_pos;
    int     size_a;

    while (*stack_b != NULL)
    {
        size_a = get_stack_size(*stack_a);
        
        // 1. Find where the top of stack_b belongs in stack_a
        target_pos = get_insertion_pos(*stack_a, (*stack_b)->index);

        // 2. Rotate stack_a to bring that target position to the top
        if (target_pos <= size_a / 2)
        {
            while (target_pos > 0)
            {
                ra(stack_a);
                target_pos--;
            }
        }
        else
        {
            while (target_pos < size_a)
            {
                rra(stack_a);
                target_pos++;
            }
        }

        // 3. Push the element from B to A
        pa(stack_a, stack_b);
    }
}

void    normalize_index(t_node **stack)
{
    t_node  *curr;
    t_node  *compare;
    int     index;

    if (!stack || !*stack)
        return ;
    curr = *stack;
    while(*curr)
    {
        compare = *stack;
        index = 0;
        while(*compare)
        {
            if (curr->nbr > compare->nbr)
                index++;
            compare = compare->down;
        }
        curr->index = index;
        curr = curr->down;
    }
}

void    chunks_sort(t_node **stack_a, t_node **stack_b)
{
    int     bucket_size;
    int     min;
    int     max;

    bucket_size = get_bucket_size(get_stack_size(stack_a));
    min = 0;
    max = bucket_size;
    while (get_stack_size(*stack_a) > 5)
    {
        if((*stack_a)->index <= max)
        {
            pb(stack_a, stack_b);
            if((*stack_b)->index < min + (bucket_size/ 2))
                rb(stack_b);
            min++;;
            max++;
        }
        else
            ra(stack_a);
    }
    sort_five(stack_a, stack_b);
    push_back_to_a(stack_a, stack_b);
}