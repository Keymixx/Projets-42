/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:05 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:26:17 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*cpylst;

	size = 0;
	cpylst = lst;
	while (cpylst != NULL)
	{
		cpylst = cpylst->next;
		size++;
	}
	return (size);
}
