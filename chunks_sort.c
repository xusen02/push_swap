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

static int  get_chunk_size(int size)
{
    if (size <= 100)
        return (15);
    return (35);
}

static void final_rotate_a(t_node **stack_a)
{
    int min_pos;
    int size_a;

    size_a = get_stack_size(*stack_a);
    min_pos = find_min_index(*stack_a);
    if (min_pos <= size_a / 2)
    {
        while (min_pos > 0)
        {
            ra(stack_a);
            min_pos--;
        }
    }
    else
    {
        while (min_pos < size_a)
        {
            rra(stack_a);
            min_pos++;
        }
    }
}

static void push_back_to_a(t_node **stack_a, t_node **stack_b)
{
    int max_pos;
    int size_b;

    while (*stack_b != NULL)
    {
        size_b = get_stack_size(*stack_b);
        max_pos = find_max_index(*stack_b);
        if (max_pos <= size_b / 2)
        {
            while (max_pos > 0)
            {
                rb(stack_b);
                max_pos--;
            }
        }
        else
        {
            while (max_pos < size_b)
            {
                rrb(stack_b);
                max_pos++;
            }
        }
        pa(stack_a, stack_b);
    }
}

void    chunks_sort(t_node **stack_a, t_node **stack_b)
{
    int size;
    int chunk_size;
    int min;
    int max;

    size = get_stack_size(*stack_a);
    chunk_size = get_chunk_size(size);
    min = 0;
    max = chunk_size;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->index < max)
        {
            pb(stack_a, stack_b);
            if ((*stack_b)->index < (min + max) / 2)
                rb(stack_b);
            min++;
            max++;
        }
        else
            ra(stack_a);
    }
    push_back_to_a(stack_a, stack_b);
    final_rotate_a(stack_a);
}