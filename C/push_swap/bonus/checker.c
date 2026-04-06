/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 00:18:49 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/18 00:56:35 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char *av[])
{
	t_stack *a = build_stack(ac, av);
	t_stack *b;
	algo(&a,&b);
	int fd = 1;
	int i = 0;
	printf(" \n\n\n ICI GNL\n\n\n");
	while(i++ < 20)
	{
		get_next_line(1);
	}
	
}