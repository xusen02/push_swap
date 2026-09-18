/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:51 by txu-sen           #+#    #+#             */
/*   Updated: 2026/09/02 15:33:53 by txu-sen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stddef.h>
#include <unistd.h>

typedef struct s_node
{
    int             nbr;
    int             index;
    struct s_node   *down;
    struct s_node   *up;
}   t_node;

/* Parsing & Validation */
int	ft_atoi(const char *str);
int	is_valid(char *str);
int	repeat_nbr(t_node *tung_tung, int nbr);
int	in_nbr(int argc, char **argv, t_node **tung_tung);
int	store_in(t_node *new_node, t_node **tung_tung);
int	push_swap(int argc, char **argv, t_node **stack_a);
void        	free_stack(t_node **stack);
t_node      		*create_node(int nbr);

/* Stack Utilities & Sorting Logic */
int	get_stack_size(t_node *stack);
int	pick_swap(t_node **stack_a, t_node **stack_b);
int	is_sorted(t_node *a);
int	find_max(t_node *a);
int find_min(t_node *a);
int	find_min_index(t_node *stack);
int find_max_index(t_node *stack);
void        normalize_index(t_node **stack);
void		sort_three(t_node **stack_a);
void		sort_five(t_node **stack_a, t_node **stack_b);
void        radix_sort(t_node **a, t_node **b);
void        adaptive_sort(t_node **a, t_node **b);

/* Operations */
void		sa(t_node **stack_a);
void		sb(t_node **stack_a);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_a);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_a);
void		rrr(t_node **stack_a, t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		do_sa(t_node **stack_a);
void		do_sb(t_node **stack_a);
void		do_pa(t_node **stack_a, t_node **stack_b);
void		do_pb(t_node **stack_a, t_node **stack_b);
void		do_ra(t_node **stack_a);
void		do_rb(t_node **stack_a);
void		do_rra(t_node **stack_a);
void		do_rrb(t_node **stack_a);
void		do_rrr(t_node **stack_a, t_node **stack_b);
void		do_ss(t_node **stack_a, t_node **stack_b);
void		do_rr(t_node **stack_a, t_node **stack_b);

void		selection_sort(t_node **a, t_node **b);
void        chunks_sort(t_node **stack_a, t_node **stack_b);

#endif
