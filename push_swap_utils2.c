/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:35:59 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/21 16:36:18 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	store_in(t_node *new_node, t_node **tung_tung)
{
	t_node	*last;

	if (!*tung_tung)
	{
		*tung_tung = new_node;
		new_node->up = NULL;
	}
	else
	{
		last = *tung_tung;
		while (last->down)
			last = last->down;
		last->down = new_node;
		new_node->up = last;
	}
	return (0);
}

int	repeat_nbr(t_node *stack_a, int nbr)
{
	while (stack_a)
	{
		if (stack_a->nbr == nbr)
			return (1);
		stack_a = stack_a->down;
	}
	return (0);
}

int	is_match(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (s1[i] == s2[i]);
}
