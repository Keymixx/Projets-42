/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:37:14 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/17 23:47:24 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*temp;

	if (!(*a)->next)
		return ;
	temp = lstlast(*a);
	lstlast_last(*a)->next = NULL;
	temp->next = *a;
	*a = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*temp;

	if (!(*b)->next)
		return ;
	temp = lstlast(*b);
	lstlast_last(*b)->next = NULL;
	temp->next = *b;
	*b = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a)->next || !(*b)->next)
		return ;
	temp = lstlast(*a);
	lstlast_last(*a)->next = NULL;
	temp->next = *a;
	*a = temp;
	temp = lstlast(*b);
	lstlast_last(*b)->next = NULL;
	temp->next = *b;
	*b = temp;
	write(1, "rrr\n", 4);
}

void	ra_ra(t_stack **a)
{
	ra(a);
	ra(a);
}

void	rra_rra(t_stack **a)
{
	rra(a);
	rra(a);
}
