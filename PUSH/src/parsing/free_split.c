/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:28:53 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/18 01:30:19 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_split(char **split)
{	
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}