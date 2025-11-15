/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:10:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 04:27:35 by carl             ###   ########.fr       */
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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
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
	
	ft_printf("ss\n");
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
	ft_printf("pb\n");
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
	ft_printf("pa\n");
}
