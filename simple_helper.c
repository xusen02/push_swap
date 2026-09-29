/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:33:51 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/29 13:34:12 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	positive(int input)
{
	if (input > 0)
		return (input);
	return (input * (-1));
}

void	run_a(t_node **a, t_bench *bench, int cost)
{
	if (cost > 0)
	{
		while (cost--)
			ra(a, bench);
	}
	else
	{
		while (cost++ < 0)
			rra(a, bench);
	}
}

void	run_b(t_node **b, t_bench *bench, int cost)
{
	if (cost > 0)
	{
		while (cost--)
			rb(b, bench);
	}
	else
	{
		while (cost++ < 0)
			rrb(b, bench);
	}
}
