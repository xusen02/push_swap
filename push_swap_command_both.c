/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_both.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:35 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/02 15:33:36 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	do_rrr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (!*stack_a || !*stack_b)
		return ;
	do_rra(stack_a);
	do_rrb(stack_b);
}

void	do_ss(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (!*stack_a || !*stack_b)
		return ;
	do_sa(stack_a);
	do_sb(stack_b);
}

void	do_rr(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (!*stack_a || !*stack_b)
		return ;
	do_ra(stack_a);
	do_rb(stack_b);
}
