/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:27:48 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/17 12:52:55 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*cpymap;
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		cpymap = ft_lstnew(lst->content);
		if (cpymap == NULL)
		{
			ft_lstclear (&map, del);
			ft_lstdelone (cpymap, del);
			return NULL;
		}
		f(cpymap->content);
		ft_lstadd_back(&map, cpymap);
		lst = temp;
	}
	map->next = NULL;
	return (map);
}