/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 03:16:59 by carl              #+#    #+#             */
/*   Updated: 2025/11/15 04:28:48 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a) 
{
    int first;
    int second;
    int third;

    first = (*a)->index;
    second = (*a)->next->index;
    third = (*a)->next->next->index;
    if (first > second && second < third)
        sa(a);
    else if (third > second && second > first)
    {
        sa(a);
        rra(a);
    }
}