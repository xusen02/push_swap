#include "push_swap.h"

void    sb(t_node **stack_b)
{
    do_sb(stack_b);
    write(1, "sb\n", 3);
}

void    pb(t_node **stack_a, t_node **stack_b)
{
    do_pb(stack_a, stack_b);
    write(1, "pb\n", 3);
}

void    rb(t_node **stack_b)
{
    do_rb(stack_b);
    write(1, "rb\n", 3);
}

void    rrb(t_node **stack_b)
{
    do_rrb(stack_b);
    write(1, "rrb\n", 4);
}