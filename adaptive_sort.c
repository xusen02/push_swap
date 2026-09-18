/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:02:57 by zyeo              #+#    #+#             */
/*   Updated: 2026/09/18 13:02:58 by zyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	adaptive_sort(t_node **a, t_node **b)
{
	double	disorder;

	if (!a || !*a)
		return ;
	disorder = compute_disorder(a);
	if (disorder < 0.2)
		selection_sort(a, b);
	else if (disorder < 0.5)
		chunks_sort(a, b);
	else
		radix_sort(a, b);
}
