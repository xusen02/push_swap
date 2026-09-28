#include "push_swap.h"

int abs(int input) 
{ 
    if (input > 0) 
        return (input);
    return (input * (-1));
} 
 
int calc_cost(t_node **stack, int nbr) 
{ 
    int index;
    t_node  *current;
    
    index = 0;
    current = *stack;
    while (current) 
    { 
        if (current->nbr == nbr)
            break ;
        current = current->down; 
        index++; 
    } 
    if (get_stack_size(*stack) / 2 > index)
        return (index);
    return (index - get_stack_size(*stack));
} 

int find_a_position(t_node **a, int b) 
{
    t_node  *current;
    t_node  *position;

    current = *a;
    position = NULL;
    while (current) 
    { 
        if (current->nbr > b)
        {
            if (!position || current->nbr < position->nbr)
                position = current;
        }
        current = current->down; 
    }
    if (position)
        return (position->nbr);
    return (find_min(*a)); 
}

void execute(t_node **a, t_node **b, t_node *cheapest) 
{ 
    int b_cost;
    int a_cost;

    b_cost = calc_cost(b, cheapest->nbr);
    a_cost = calc_cost(a, find_a_position(a, cheapest->nbr));
    if (b_cost > 0) 
    { 
        while (b_cost--) 
            rb(a, b);
    } 
    else 
    {
        while (b_cost < 0) 
            rrb(a, b);
    }
    if (a_cost > 0) 
    {
        while (a_cost--) 
            ra(a, b);
    }
    else
    {
        while (a_cost < 0)
            rra(a, b); 
    }
    pa(a, b);
} 

void find_cheapest(t_node **a, t_node **b, t_cost *cost) 
{ 
    int cheapest;
    t_node  *current;

    current = *b;
    cheapest = 2147483647; 
    while (current) 
    { 
        cost->cost_a = calc_cost(a, find_a_position(a, current->nbr));
        cost->cost_b = calc_cost(b, current->nbr); 
        cost->total = abs(cost->cost_a) + abs(cost->cost_b); 
        if (cost->total < cheapest) 
        { 
            cheapest = cost->total; 
            cost->cheapest = current;
        } 
        current = current->down; 
    } 
} 

void simple_sort(t_node **a, t_node **b, t_bench *bench) 
{ 
    t_cost cost; 
    
    while (get_stack_size(*a) > 3) 
        pb(a, b, bench); 
    sort_three(a, bench); 
    while (*b) 
    { 
        find_cheapest(a, b, &cost); 
        execute(a, b, cost.cheapest); 
    }
    rotate_until_sorted(a);
}
