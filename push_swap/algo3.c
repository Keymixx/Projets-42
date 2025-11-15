/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 03:16:59 by carl              #+#    #+#             */
/*   Updated: 2025/11/15 21:03:48 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool already_sort(t_stack *a)
{
    t_stack *current;
    int     previous;

    current = a;
    previous = INT_MIN;
    while (current)
    {
        if (current->index < previous)
            return (false);
        previous = current->index;
        current = current->next; 
    }
    return (true);
}

void sort_three(t_stack **a) 
{
    int first;
    int second;
    int third;

    first = (*a)->index;
    second = (*a)->next->index;
    third = (*a)->next->next->index;
    if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }    
    else if (first < second && second > third && first > third) 
        rra(a);
    else if (first < second && second > third && first < third)
    {
        rra(a);
        sa(a);
    }
    else if (first > second && second < third)
    {
        rra(a);
        rra(a);
    }
}

void sort_five(t_stack **a, t_stack **b) 
{
    int min_pos;
    
    min_pos = find_min(*a);
    if (min_pos == 1)
        sa(a);
    else if (min_pos == 2) 
    {
        ra(a);
        ra(a);
    }
    else if (min_pos == 3) 
    {
        rra(a);
        rra(a);
    }
    else if (min_pos == 4)
        rra(a);
    pb(a, b);
    min_pos = find_min(*a); 
    if (min_pos == 1)
        sa(a);
    else if (min_pos == 2) {
        ra(a);
        ra(a);
    }
    else if (min_pos == 3)
        rra(a);
    pb(a, b);
    sort_three(a);
    pa(b, a);
    pa(b, a);
}


void sort_four(t_stack **a, t_stack **b) 
{   
    int min_pos = find_min(*a);

    if (min_pos == 1)
        sa(a);
    else if (min_pos == 2) 
    {
        ra(a);
        ra(a);
    }
    else if (min_pos == 3)
        rra(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void homemade_sort(t_stack **a, t_stack **b)
{
    if (lstsize(*a) == 1)
        return;
    else if (lstsize(*a) == 2 && ((*a)->index < (*a)->next->index))
        sa(a);
    else if (lstsize(*a) == 4)
        sort_four(a, b);
    else if (lstsize(*a) == 5)
        sort_five(a, b);
}
