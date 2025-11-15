/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:52:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 04:08:52 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **a)
{
	t_stack *temp;

	if (!(*a)->next)
		return;
	temp = *a;
	*a= (*a)->next;
	temp->next = NULL;
	lstlast(*a)->next = temp;
	ft_printf("ra\n");
}

void rb(t_stack **b)
{
	t_stack *temp;

	if (!(*b)->next)
		return;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	lstlast(*b)->next = temp;
	ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!(*a)->next || !(*b)->next)
		return;
	temp = *a;
	*a= (*a)->next;
	temp->next = NULL;
	lstlast(*a)->next = temp;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	lstlast(*b)->next = temp;
	ft_printf("rr\n");
}