/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:44:02 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:48:03 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_index(t_stack *b, int pos_b)
{
    int i;
    t_stack *current;

    current = b;
    i = 0;
    while (i != pos_b)
    {
        i++;
        current = current->next;
    }
    return (current->index);
}
int find_min(t_stack *a)
{
    t_stack *current;
    int min_index;
    int i;
    int min_pos;

    current = a;
    min_index = INT_MAX;
    min_pos = 0;
    i = 0;
    while (current)
    {
        if (current->index < min_index )
        {
            min_index = current->index;
            min_pos = i;
        }
        i++;
        current = current->next;
    }
    return (min_pos);
}

int find_target(t_stack *a, int index)
{
    t_stack *current;
    int good_pos;
    int best_index;
    int i;

    current = a;
    good_pos = 0;
    i = 0;
    best_index = INT_MAX;
    while (current)
    {
        if (current->index > index && current->index < best_index )
        {
            best_index = current->index;
            good_pos = i;
        }
        i++;
        current = current->next;
    }
    if (best_index == INT_MAX)
        good_pos = find_min(a);
    return (good_pos);
}

int calcul_cost(t_stack *a, t_stack *b, int pos_b)
{
    int cost;
    int size_a;
    int size_b;
    int pos_a;

    cost = 0;
    size_a = lstsize(a);
    size_b = lstsize(b);
    pos_a = find_target(a, find_index(b,pos_b));
    
    if (pos_b <= size_b / 2)
        cost = pos_b;
    else
        cost = size_b - pos_b;
    if (pos_a <= size_a / 2)
        cost += pos_a;
    else 
        cost += size_a - pos_a;
    return (cost);
}