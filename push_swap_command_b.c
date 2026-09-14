/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:57:32 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/07 11:57:38 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrb(t_node **stack)
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

void	do_sb(t_node **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->down)
		return ;
	temp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->down->nbr;
	(*stack)->down->nbr = temp;
}

void	do_rb(t_node **stack)
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

void	do_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = temp->down;
	temp->down = *stack_b;
	*stack_b = temp;
}