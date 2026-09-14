/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:35 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/02 15:33:36 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_node **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->down)
		return ;
	temp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->down->nbr;
	(*stack)->down->nbr = temp;
}

void	do_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = temp->down;
	temp->down = *stack_a;
	*stack_a = temp;
}

void	do_rra(t_node **stack)
{
	t_node	*end;
	t_node	*last;
    t_node  *head;

	if (!stack || !(*stack) || !(*stack)->down)
		return ;
    head = *stack;
	end = NULL;
    last = *stack;
    while (last->down)
    {
        end = last;
        last = last->down;
    }
    *stack = last;
    last->down = head;
    end->down = NULL;
}

void	do_ra(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->down)
		return ;
	first = *stack;
	*stack = first->down;
	last = *stack;
	while (last->down)
		last = last->down;
	last->down = first;
	first->down = NULL;
}

