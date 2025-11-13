/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:33:31 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/09 21:27:25 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_index(char **split, int n)
{
	int	i;
	int index;
	
	i = 0;
	index = 0;
	while (split[i])
	{
		if (ft_atoi(split[i]) == ft_atoi(split[n]) && n != i)
			return (-1);
		if (ft_atoi(split[i]) < ft_atoi(split[n]) && n != i)
			index++;
		i++;
	}
	return(index);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		split[i] = NULL;
		free (split[i++]);
	}
	split = NULL;
	free (split);
}

int build_stack_str(t_stack **stack_a, char *str)
{
	char 	**split;
	int		i;
	int		index;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		index = choose_index(split, i);
		if (index == -1)
			return (0);
		lstadd_back(stack_a, lstnew(ft_atoi(split[i]), index));
		i++;
	}
	free_split(split);
	return (1);
}

int build_stack_params(t_stack **stack_a, int count, char *params[])
{
	int		i;
	int		index;

	
	i = 1;
	while (i < count)
	{
		index = choose_index(params, i);
		if (index == -1)
			return (0);
		lstadd_back(stack_a, lstnew(ft_atoi(params[i]),index));
		i++;
	}
	write(1,"a",1);
	return (1);
}


t_stack *build_stack(int count, char *params[])
{
	t_stack *stack_a;

	stack_a = NULL;
	if (count == 2)
	{
		if (!build_stack_str(&stack_a, params[1]))
			return (NULL);
	}
	else 
	{
		if (!build_stack_params(&stack_a, count, params))
			return (NULL);
	}
	return (stack_a);
} 