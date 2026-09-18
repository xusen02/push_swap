/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 11:27:03 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/18 11:27:07 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **a, t_node **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = get_stack_size(*a);
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (size <= 10)
		selection_sort(a, b);
	else if (size <= 150)
		chunks_sort(a, b);
	else
		radix_sort(a, b);
}
