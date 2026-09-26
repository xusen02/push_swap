/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:07:56 by txu-sen          #+#    #+#             */
/*   Updated: 2026/09/20 18:15:00 by txu-sen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(int *argc, char ***argv, t_bench *bench,
							int *count_only)
{
	int	sort_type;

	sort_type = 0;
	bench->active = 0;
	while (*argc > 1)
	{
		if (is_match((*argv)[1], "--bench"))
			bench->active = 1;
		else if (is_match((*argv)[1], "--simple"))
			sort_type = 1;
		else if (is_match((*argv)[1], "--medium"))
			sort_type = 2;
		else if (is_match((*argv)[1], "--complex"))
			sort_type = 3;
		else if (is_match((*argv)[1], "--adaptive"))
			sort_type = 4;
		else if (*count_only == 1 && is_match((*argv)[1], "--count-only"))
			*count_only = -1;
		else
			break ;
		(*argv)++;
		(*argc)--;
	}
	return (sort_type);
}

static void	execute_sort(int sort_type, t_node **stack_a,
		t_node **stack_b, t_bench *bench)
{
	if (sort_type == 1)
		insertion_sort(stack_a, stack_b, bench);
	else if (sort_type == 2)
		chunks_sort(stack_a, stack_b, bench);
	else if (sort_type == 3)
		radix_sort(stack_a, stack_b, bench);
	else
		adaptive_sort(stack_a, stack_b, bench);
}

static char	*get_strategy_name(int sort_type, double disorder)
{
	if (sort_type == 1)
		return ("Simple / O(n2)");
	if (sort_type == 2)
		return ("Medium / O(n√n)");
	if (sort_type == 3)
		return ("Complex / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n2)");
	if (disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

static int	handle_sorting(t_node **stack_a, int sort_type, t_bench *bench,
							int count_only)
{
	t_node	*stack_b;
	char	*strategy_name;

	stack_b = NULL;
	calculate_disorder(*stack_a, bench);
	strategy_name = get_strategy_name(sort_type, compute_disorder(stack_a));
	normalize_index(stack_a);
	if (!is_sorted(*stack_a))
		execute_sort(sort_type, stack_a, &stack_b, bench);
	save_benchmark(bench, strategy_name);
	free_stack(stack_a);
	free_stack(&stack_b);
	if (count_only == -1)
		ft_putnbr_fd(bench->total_ops, 1);
	return (0);
}

int	push_swap(char **argv_alpha, t_node **stack_a)
{
	int		sort_type;
	t_bench	bench;
	int		argc;
	char	**argv;
	int		count_only;

	count_only = 0;
	ft_memset(&bench, 0, sizeof(t_bench));
	argv = process_argv(argv_alpha);
	argc = count_argv(argv);
	sort_type = parse_flags(&argc, &argv, &bench, &count_only);
	if (in_nbr(argc, argv, stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (handle_sorting(stack_a, sort_type, &bench, count_only));
}
