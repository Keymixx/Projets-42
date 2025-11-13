/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:52:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/10 02:49:49 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **stack)
{
	t_stack *temp;

	if (!(*stack)->next)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	lstlast(*stack)->next = temp;
}

void rb(t_stack **stack)
{
	t_stack *temp;

	if (!(*stack)->next)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	lstlast(*stack)->next = temp;
}

void rr(t_stack **stack)
{
	ra(stack);
	rb(stack);
}