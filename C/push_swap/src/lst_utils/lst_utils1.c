/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:59:12 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/17 23:09:58 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
