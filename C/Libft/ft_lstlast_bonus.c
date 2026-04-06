/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:00:48 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/17 11:55:39 by caaubert         ###   ########.fr       */
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
