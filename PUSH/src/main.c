/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:47:09 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/18 01:23:17 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("num = %d index = %d\n", stack->num, stack->index);
// 		stack = stack->next;
// 	}
// }

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

bool	check(int argc, char *argv[])
{
	if (argc == 2)
		if (!check_string(argv[1]))
			return (false);
	if (argc > 2)
		if (!check_params(argc, argv))
			return (false);
	return (true);
}

bool	is_good(t_stack *stack)
{
	t_stack	*current;
	int		previous;

	current = stack;
	previous = INT_MIN;
	while (current)
	{
		if (previous > current->num)
			return (false);
		previous = current->num;
		current = current->next;
	}
	return (true);
}

// int main(int ac, char *av[])
// {
// 	t_stack *a = build_stack(ac, av);
// 	t_stack *b;
// 	algo(&a,&b);
// 	int i = 0;
// 	printf(" \n\n\n ICI GNL\n\n\n");
// 	while(i++ < 20)
// 	{
// 		get_next_line(1);
// 	}
// }	

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (error());
	if (!check(argc, argv))
		return (error());
	stack_a = build_stack(argc, argv);
	if (stack_a == NULL)
		return (error());
	algo(&stack_a, &stack_b);
	lstclear(&stack_a);
	lstclear(&stack_b);
}
