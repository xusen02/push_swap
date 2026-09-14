/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 16:50:00 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/09 16:50:00 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *stack_a;

    if (argc < 2)
        return (0);
    stack_a = NULL;
    return (push_swap(argc, argv, &stack_a));
}
