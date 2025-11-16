/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:00:48 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:26:09 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cpylst;

	cpylst = lst;
	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	while (cpylst->next != NULL)
		cpylst = cpylst->next;
	return (cpylst);
}
