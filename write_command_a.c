/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:35 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/02 15:33:36 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_node **stack_a, t_bench *bench)
{
	do_sa(stack_a);
	write(1, "sa\n", 3);
	bench->sa++;
	bench->total_ops++;
}

void	pa(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	do_pa(stack_a, stack_b);
	write(1, "pa\n", 3);
	bench->pa++;
	bench->total_ops++;
}

void	ra(t_node **stack_a, t_bench *bench)
{
	do_ra(stack_a);
	write(1, "ra\n", 3);
	bench->ra++;
	bench->total_ops++;
}

void	rra(t_node **stack_a, t_bench *bench)
{
	do_rra(stack_a);
	write(1, "rra\n", 4);
	bench->rra++;
	bench->total_ops++;
}
