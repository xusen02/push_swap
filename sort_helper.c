/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:04:48 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/07 13:04:50 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a->down)
	{
		if (a->nbr > a->down->nbr)
			return (0);
		a = a->down;
	}
	return (1);
}

int	find_max(t_node *a)
{
	int	max;

	if (!a)
		return (0);
	max = a->nbr;
	while (a)
	{
		if (a->nbr > max)
			max = a->nbr;
		a = a->down;
	}
	return (max);
}

int	find_min(t_node *a)
{
	int	min;

	if (!a)
		return (0);
	min = a->nbr;
	while (a)
	{
		if (a->nbr < min)
			min = a->nbr;
		a = a->down;
	}
	return (min);
}

int	find_min_index(t_node *stack)
{
	int	min;
	int	index;
	int	i;

	if (!stack)
		return (0);
	min = stack->nbr;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			index = i;
		}
		stack = stack->down;
		i++;
	}
	return (index);
}

int	find_max_index(t_node *stack)
{
	int	max;
	int	index;
	int	i;

	if (!stack)
		return (0);
	max = stack->nbr;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			index = i;
		}
		stack = stack->down;
		i++;
	}
	return (index);
}
