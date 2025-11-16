/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:10:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/16 17:23:19 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	write(1,"sa\n",3);
}

void sb(t_stack **stack)
{
	t_stack *temp1;
	t_stack *temp2;

	if(!*stack || !(*stack)->next)
		return;
	temp1 = (*stack)->next;
	temp2 = *stack;
	(*stack)->next = (*stack)->next->next;
	*stack = temp1;
	(*stack)->next = temp2;
	write(1,"sb\n",3);
}


void ss(t_stack **a, t_stack **b)
{
	t_stack *temp1;
	t_stack *temp2;
	
	if(!*a || !(*a)->next || !*b || !(*b)->next)
		return;
	temp1 = (*a)->next;
	temp2 = *a;
	(*a)->next = (*a)->next->next;
	*a = temp1;
	(*a)->next = temp2;
	
	temp1 = (*b)->next;
	temp2 = *b;
	(*b)->next = (*b)->next->next;
	*b = temp1;
	(*b)->next = temp2;
	
	write(1,"ss\n",3);
}

void pb(t_stack **a,t_stack **b)
{
	t_stack *temp;
	
	if(!*a)
		return;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1,"pb\n",3);
}

void pa(t_stack **b,t_stack **a)
{
	t_stack *temp;
	
	if(!*b)
		return;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1,"pa\n",3);
}
