/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:47:09 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/09 03:57:05 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("num = %d index = %d\n",stack_a->num, stack_a->index);
		stack_a = stack_a ->next;
	}
}

bool check(int argc, char *argv[])
{
	if (argc == 2)
		if (!check_string(argv[1]))
			return (false);
	if (argc > 2)
		if (!check_params(argc,argv))
			return (false);
	return (true);
}

int main(int argc, char *argv[])
{
	t_stack *stack_a;
	
	if (argc == 1)
		return (1);
	if(!check(argc, argv))
		return(ft_printf("Error\n"),1);
		
	else
		ft_printf("C'est good\n");
	stack_a = build_stack(argc, argv);
	print_stack(stack_a);	
}