#include "push_swap.h"

void    ss(t_node **stack_a, t_node **stack_b)
{
    do_sa(stack_a);
    do_sb(stack_b);
    write(1, "ss\n", 3);
}

void    rr(t_node **stack_a, t_node **stack_b)
{
    do_ra(stack_a);
    do_rb(stack_b);
    write(1, "rr\n", 3);
}

void    rrr(t_node **stack_a, t_node **stack_b)
{
    do_rra(stack_a);
    do_rrb(stack_b);
    write(1, "rrr\n", 4);
}