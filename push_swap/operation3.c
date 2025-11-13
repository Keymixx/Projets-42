/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:37:14 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/10 02:50:14 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **stack)
{	
	t_stack *temp;

	if (!(*stack)->next)
		return;
	temp = lstlast(*stack);
	lstlast_last(*stack)->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void rrb(t_stack **stack)
{	
	t_stack *temp;
	
	if (!(*stack)->next)
		return;
	temp = lstlast(*stack);
	lstlast_last(*stack)->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void rrr(t_stack **stack)
{	
	rra(stack);
	rrb(stack);
}