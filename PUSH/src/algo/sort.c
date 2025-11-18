/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:17:51 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/17 23:46:35 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_rotation_b(t_stack *b, int pos_b)
{
	int	count_rotation;

	count_rotation = 0;
	if (pos_b <= (lstsize(b) / 2))
		count_rotation = pos_b;
	else
		count_rotation -= lstsize(b) - pos_b;
	return (count_rotation);
}

int	count_rotation_a(t_stack *a, t_stack *b, int pos_b)
{
	int	count_rotation;
	int	pos_a;

	count_rotation = 0;
	pos_a = find_target(a, find_index(b, pos_b));
	if (pos_a <= (lstsize(a) / 2))
		count_rotation = pos_a;
	else
		count_rotation -= lstsize(a) - pos_a;
	return (count_rotation);
}

void	mini_sort_stack(t_stack **a, t_stack **b, int c_a, int c_b)
{
	while (c_b > 0)
	{
		rb(b);
		c_b--;
	}
	while (c_b < 0)
	{
		rrb(b);
		c_b++;
	}
	while (c_a > 0)
	{
		ra(a);
		c_a--;
	}
	while (c_a < 0)
	{
		rra(a);
		c_a++;
	}
}

void	sort_stack(t_stack **a, t_stack **b, int pos_b)
{
	int	r_a_count;
	int	r_b_count;

	r_a_count = count_rotation_a(*a, *b, pos_b);
	r_b_count = count_rotation_b(*b, pos_b);
	while (r_b_count > 0 && r_a_count > 0)
	{
		rr(a, b);
		r_a_count--;
		r_b_count--;
	}
	while (r_b_count < 0 && r_a_count < 0)
	{
		rrr(a, b);
		r_a_count++;
		r_b_count++;
	}
	mini_sort_stack(a, b, r_a_count, r_b_count);
}
