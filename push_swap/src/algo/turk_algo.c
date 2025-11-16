/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 00:23:37 by carl              #+#    #+#             */
/*   Updated: 2025/11/16 01:16:45 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int choose_best(t_stack *a, t_stack *b)
{
    int i;
    int size_b;
    int best_cost;
    int best_pos;

    i = 0;
    size_b = lstsize(b);
    best_cost = INT_MAX;
    best_pos = 0;
    while (i < size_b)
    {
        if (calcul_cost(a, b, i) < best_cost)
        {
            best_cost = calcul_cost(a, b, i);
            best_pos = i;
        }
        i++;
    }
    return (best_pos);
}
int count_rotation_b(t_stack *b, int pos_b)
{
    int count_rotation;

    count_rotation = 0;
    if (pos_b <= (lstsize(b) / 2))
        count_rotation = pos_b;
    else 
        count_rotation -= lstsize(b) - pos_b;
    return(count_rotation);
}

int count_rotation_a(t_stack *a, t_stack *b,int pos_b)
{
    int count_rotation;
    int pos_a;

    count_rotation = 0;
    pos_a = find_target(a, find_index(b, pos_b));
    if (pos_a <= (lstsize(a) / 2))
        count_rotation = pos_a;
    else 
        count_rotation -= lstsize(a) - pos_a;
    return (count_rotation);
}

void sort_stack(t_stack **a, t_stack **b, int pos_b)
{
    int r_a_count;
    int r_b_count;
    
    r_a_count = count_rotation_a(*a, *b, pos_b);
    r_b_count = count_rotation_b(*b, pos_b);
    while (r_b_count > 0 && r_a_count > 0)
    {
        rr(a,b);
        r_a_count--;
        r_b_count--;
    }
    while (r_b_count < 0 && r_a_count < 0)
    {
        rrr(a,b);
        r_a_count++;
        r_b_count++;
    }
    while (r_b_count > 0)
    {
        rb(b);
        r_b_count--;
    }
    while (r_b_count < 0)
    {
        rrb(b);
        r_b_count++;
    }
    while (r_a_count > 0)
    {
        ra(a);
        r_a_count--;
    }
    while (r_a_count < 0)
    {
        rra(a);
        r_a_count++;
    }
}

void algo(t_stack **a, t_stack **b)
{
    int best_pos;
    int r_a_count;

    if (already_sort(*a))
        return;
    if (lstsize(*a) <= 5)
    {
           homemade_sort(a, b);
           return;
    }
    while (lstsize(*a) > 3)
        pb(a,b);
    sort_three(a);
    while (*b != NULL)
    {
         best_pos = choose_best(*a, *b);
         sort_stack(a, b, best_pos);
         pa(b,a); 
    }
    r_a_count = count_rotation_b(*a, find_min(*a));
    while (r_a_count > 0)
    {
        ra(a);
        r_a_count--;
    }
    while (r_a_count< 0)
    {
        rra(a);
        r_a_count++;
    }
}
