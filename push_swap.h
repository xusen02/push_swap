/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:33:51 by txu-sen          #+#    #+#             */
/*   Updated: 2026/09/02 15:33:53 by txu-sen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*down;
	struct s_node	*up;
}				t_node;

typedef struct s_bench
{
	int				active;
	int				sa;
	int				sb;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rrr;
	int				ss;
	int				rr;
	int				total_ops;
	int				disorder_pct;
	int				disorder_dec;
}				t_bench;

/* Parsing & Validation */
int		ft_atoi(const char *str);
int		is_valid(char *str);
int		repeat_nbr(t_node *tung_tung, int nbr);
int		in_nbr(int argc, char **argv, t_node **tung_tung);
int		store_in(t_node *new_node, t_node **tung_tung);
int		push_swap(char **argv, t_node **stack_a);
int		is_match(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	free_stack(t_node **stack);
t_node	*create_node(int nbr);

/*one for all*/
int		count_argv(char **argv);
char	**ft_split(char const *s, char c);
char	**process_argv(char **argv_alpha);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

/*bench_helpers*/
void	calculate_disorder(t_node *stack_a, t_bench *bench);
void	save_benchmark(t_bench *bench, char *strategy_name);
void	write_bench_file(int fd, t_bench *bench, char *strategy_name);
void	write_bench_file2(int fd, t_bench *bench);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int fd);

/* Stack Utilities & Sorting Logic */
int		get_stack_size(t_node *stack);
int		is_sorted(t_node *a);
int		find_max(t_node *a);
int		find_min(t_node *a);
int		find_min_index(t_node *stack);
int		find_max_index(t_node *stack);
double	compute_disorder(t_node **stack_a);
void	normalize_index(t_node **stack);
void	sort_three(t_node **stack_a, t_bench *bench);
void	sort_five(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	radix_sort(t_node **a, t_node **b, t_bench *bench);
void	adaptive_sort(t_node **a, t_node **b, t_bench *bench);
void	insertion_sort(t_node **a, t_node **b, t_bench *bench);
void	chunks_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);

/* Operations */
void	sa(t_node **stack_a, t_bench *bench);
void	sb(t_node **stack_a, t_bench *bench);
void	pa(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	pb(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ra(t_node **stack_a, t_bench *bench);
void	rb(t_node **stack_a, t_bench *bench);
void	rra(t_node **stack_a, t_bench *bench);
void	rrb(t_node **stack_a, t_bench *bench);
void	rrr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	rr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	do_sa(t_node **stack_a);
void	do_sb(t_node **stack_a);
void	do_pa(t_node **stack_a, t_node **stack_b);
void	do_pb(t_node **stack_a, t_node **stack_b);
void	do_ra(t_node **stack_a);
void	do_rb(t_node **stack_a);
void	do_rra(t_node **stack_a);
void	do_rrb(t_node **stack_a);
void	do_rrr(t_node **stack_a, t_node **stack_b);
void	do_ss(t_node **stack_a, t_node **stack_b);
void	do_rr(t_node **stack_a, t_node **stack_b);

#endif
