#include "push_swap.h"

void    sa(t_node **stack_a)
{
    do_sa(stack_a);
    write(1, "sa\n", 3);
}

void    pa(t_node **stack_a, t_node **stack_b)
{
    do_pa(stack_a, stack_b);
    write(1, "pa\n", 3);
}

void    ra(t_node **stack_a)
{
    do_ra(stack_a);
    write(1, "ra\n", 3);
}

void    rra(t_node **stack_a)
{
    do_rra(stack_a);
    write(1, "rra\n", 4);
}