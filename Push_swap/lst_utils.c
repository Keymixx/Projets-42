/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:59:12 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/09 02:44:01 by caaubert         ###   ########.fr       */
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
void	lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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

void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
}
void	lstclear(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(lst);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}