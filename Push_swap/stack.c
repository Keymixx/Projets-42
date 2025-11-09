/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:33:31 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/09 04:10:34 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

void build_stack_str(t_stack **stack_a, char *str)
{
	char 	**split;
	int		i;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		lstadd_back(stack_a, lstnew(ft_atoi(split[i]), i));
		i++;
	}
	free_split(split);
}

void build_stack_params(t_stack **stack_a, int count, char *params[])
{
	char 	**split;
	int		i;
	int		j;
	int		index;

	
	i = 1;
	j = 0;
	index = 0;
	while (i < count)
	{
		split = ft_split(params[i], ' ');
		while (split[j])
		{
			lstadd_back(stack_a, lstnew(ft_atoi(split[j]), index));
			j++;
			index++;
		}
		j = 0;
		i++;
		free_split(split);
	}
}

t_stack *build_stack(int count, char *params[])
{
	t_stack *stack_a;

	stack_a = NULL;
	if (count == 2)
		build_stack_str(&stack_a, params[1]);
	else 
		build_stack_params(&stack_a, count, params);
	return (stack_a);
} 