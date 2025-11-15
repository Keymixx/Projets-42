/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:59:12 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 19:45:26 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int num, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = index;
	node->next = NULL;
	return (node);
}

int	lstsize(t_stack *lst)
{
	int		size;
	t_stack	*cpylst;

	size = 0;
	cpylst = lst;
	while (cpylst != NULL)
	{
		cpylst = cpylst->next;
		size++;
	}
	return (size);
}


t_stack	*lstlast(t_stack *lst)
{
	t_stack	*cpylst;

	cpylst = lst;
	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	while (cpylst->next != NULL)
		cpylst = cpylst->next;
	return (cpylst);
}

t_stack	*lstlast_last(t_stack *lst)
{
	t_stack	*cpylst;

	cpylst = lst;
	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	while (cpylst->next->next != NULL)
		cpylst = cpylst->next;
	return (cpylst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
}

void	lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack *next;

	if(!lst || !*lst)
		return;
	current = *lst;
	while (current)
	{
		next= current->next;
		free(current);
		current = next;
	}
	*lst = NULL; 
}