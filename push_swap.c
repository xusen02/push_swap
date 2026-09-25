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

static void	parse_flags(int *argc, char ***argv, t_bench *bench, int *sort_type)
{
	*sort_type = 0;
	bench->active = 0;
	while (*argc > 1)
	{
		if (is_match((*argv)[1], "--bench"))
			bench->active = 1;
		else if (is_match((*argv)[1], "--simple"))
			*sort_type = 1;
		else if (is_match((*argv)[1], "--medium"))
			*sort_type = 2;
		else if (is_match((*argv)[1], "--complex"))
			*sort_type = 3;
		else if (is_match((*argv)[1], "--adaptive"))
			*sort_type = 4;
		else
			break ;
		(*argv)++;
		(*argc)--;
	}
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

static char	*get_strategy_name(int sort_type)
{
	if (sort_type == 1)
		return ("Simple / insertion");
	if (sort_type == 2)
		return ("Medium / Chunk");
	if (sort_type == 3)
		return ("Complex / Radix");
	return ("Adaptive / O(n√n)");
}

static int	handle_sorting(t_node **stack_a, int sort_type, t_bench *bench)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (is_sorted(*stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	calculate_disorder(*stack_a, bench);
	normalize_index(stack_a);
	execute_sort(sort_type, stack_a, &stack_b, bench);
	save_benchmark(bench, get_strategy_name(sort_type));
	free_stack(stack_a);
	free_stack(&stack_b);
	return (0);
}

int	push_swap(char **argv_alpha, t_node **stack_a)
{
	int		sort_type;
	t_bench	bench;
	int		argc;
	char	**argv;

	ft_memset(&bench, 0, sizeof(t_bench));
	argv = process_argv(argv_alpha);
	argc = count_argv(argv);
	parse_flags(&argc, &argv, &bench, &sort_type);
	if (in_nbr(argc, argv, stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (handle_sorting(stack_a, sort_type, &bench));
}
