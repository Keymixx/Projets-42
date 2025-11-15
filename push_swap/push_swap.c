/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:47:09 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 04:25:16 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("num = %d index = %d\n",stack->num, stack->index);
		stack = stack->next;
	}
}
int error(void)
{
	write(1,"Error\n",6);
	return (1);
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
	t_stack *stack_b;
	
	stack_b = NULL;
	if (argc == 1)
		return (error());
	if(!check(argc, argv))
		return (error());
	stack_a = build_stack(argc, argv);
	if (stack_a == NULL)
		return (error());
	ft_printf("\n");
	ft_printf("stack a :\n");
	print_stack(stack_a);
	ft_printf("stack b :\n");
	print_stack(stack_b);
	ft_printf("\n");
	
	// rr(&stack_a, &stack_b);
	// ra(&stack_a);
	// rb(&stack_b);
	// rra(&stack_a);
	// rrb(&stack_b);
	// rrr(&stack_a, &stack_b);

	// rra(&stack_a);
	// rra(&stack_a);
	// rb(&stack_b);
	// ft_printf("%d\n",choose_best(stack_a,stack_b));
	// sort_stack(&stack_a, &stack_b, 0);
	// ft_printf("%p\n", stack_b);
	algo(&stack_a, &stack_b);
	// sort_three(&stack_a);
	ft_printf("\nstack a :\n");
	print_stack(stack_a);
	ft_printf("stack b :\n");
	print_stack(stack_b);		
}