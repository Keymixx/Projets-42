/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:52:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/17 23:46:56 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;

	if (!(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	lstlast(*a)->next = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*temp;

	if (!(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	lstlast(*b)->next = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a)->next || !(*b)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	lstlast(*a)->next = temp;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	lstlast(*b)->next = temp;
	write(1, "rr\n", 3);
}
