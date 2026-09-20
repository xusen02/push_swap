/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command_both.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:35 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/02 15:33:36 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	do_sa(stack_a);
	do_sb(stack_b);
	if (!bench->active)
		write(1, "ss\n", 3);
	bench->ss++;
	bench->total_ops++;
}

void	rr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	do_ra(stack_a);
	do_rb(stack_b);
	if (!bench->active)
		write(1, "rr\n", 3);
	bench->rr++;
	bench->total_ops++;
}

void	rrr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	do_rra(stack_a);
	do_rrb(stack_b);
	if (!bench->active)
		write(1, "rrr\n", 4);
	bench->rrr++;
	bench->total_ops++;
}
