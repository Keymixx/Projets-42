/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:10:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/10 02:48:03 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack)
{
	t_stack *temp1;
	t_stack *temp2;

	if(!stack || !(*stack)->next)
		return;
	temp1 = (*stack)->next;
	temp2 = *stack;
	(*stack)->next = (*stack)->next->next;
	*stack = temp1;
	(*stack)->next = temp2;
}

void sb(t_stack **stack)
{
	t_stack *temp1;
	t_stack *temp2;

	if(!stack || !(*stack)->next)
		return;
	temp1 = (*stack)->next;
	temp2 = *stack;
	(*stack)->next = (*stack)->next->next;
	*stack = temp1;
	(*stack)->next = temp2;
}


void ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(t_stack **stack_a,t_stack **stack_b)
{
	t_stack *temp;
	
	if(!*stack_a)
		return;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void pb(t_stack **stack_b,t_stack **stack_a)
{
	t_stack *temp;
	
	if(!*stack_b)
		return;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}
