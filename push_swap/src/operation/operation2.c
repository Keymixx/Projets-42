/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:52:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:48:51 by carl             ###   ########.fr       */
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
	write(1,"ra\n",3);
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
	write(1,"rb\n",3);
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
	write(1,"rr\n",3);
}