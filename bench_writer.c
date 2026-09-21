/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_writer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:35:00 by txu-sen          #+#    #+#             */
/*   Updated: 2026/09/20 19:00:00 by txu-sen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	count_inversions(t_node *stack_a, long *total)
{
	t_node	*i;
	t_node	*j;
	long	inv;

	inv = 0;
	*total = 0;
	i = stack_a;
	while (i)
	{
		(*total)++;
		j = i->down;
		while (j)
		{
			if (i->nbr > j->nbr)
				inv++;
			j = j->down;
		}
		i = i->down;
	}
	return (inv);
}

void	calculate_disorder(t_node *stack_a, t_bench *bench)
{
	long	inv;
	long	total;
	long	max_pairs;
	long	scaled;

	if (!bench || !bench->active || !stack_a || !stack_a->down)
		return ;
	inv = count_inversions(stack_a, &total);
	max_pairs = (total * (total - 1)) / 2;
	if (max_pairs == 0)
		return ;
	scaled = (inv * 10000) / max_pairs;
	bench->disorder_pct = (int)(scaled / 100);
	bench->disorder_dec = (int)(scaled % 100);
}

void	save_benchmark(t_bench *bench, char *strategy_name)
{
	if (!bench || !bench->active)
		return ;
	write_bench_file(2, bench, strategy_name);
	write_bench_file2(2, bench);
}
