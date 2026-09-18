/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:35 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/02 15:33:36 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sb(t_node **stack_b)
{
	do_sb(stack_b);
	write(1, "sb\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	do_pb(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	rb(t_node **stack_b)
{
	do_rb(stack_b);
	write(1, "rb\n", 3);
}

void	rrb(t_node **stack_b)
{
	do_rrb(stack_b);
	write(1, "rrb\n", 4);
}
