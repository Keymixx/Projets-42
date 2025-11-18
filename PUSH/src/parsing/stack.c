/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:33:31 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/18 01:31:31 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	choose_index_string(char **split, int n)
{
	int	i;
	int	index;

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
	return (index);
}

int	choose_index_params(char **params, int n)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (params[i])
	{
		if (ft_atoi(params[i]) == ft_atoi(params[n]) && n != i)
			return (-1);
		if (ft_atoi(params[i]) < ft_atoi(params[n]) && n != i)
			index++;
		i++;
	}
	return (index);
}

int	build_stack_str(t_stack **stack_a, char *str)
{
	char	**split;
	int		i;
	int		index;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		index = choose_index_string(split, i);
		if (index == -1)
		{
			free_split(split);
			lstclear(stack_a);
			return (0);
		}
		lstadd_back(stack_a, lstnew(ft_atoi(split[i]), index));
		i++;
	}
	free_split(split);
	return (1);
}

bool	build_stack_params(t_stack **stack_a, int count, char *params[])
{
	int	i;
	int	index;

	i = 1;
	while (i < count)
	{
		index = choose_index_params(params, i);
		if (index == -1)
			return (false);
		lstadd_back(stack_a, lstnew(ft_atoi(params[i]), index));
		i++;
	}
	return (true);
}

t_stack	*build_stack(int count, char *params[])
{
	t_stack	*stack_a;

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
