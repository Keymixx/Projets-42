/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 00:23:37 by carl              #+#    #+#             */
/*   Updated: 2025/11/17 23:18:48 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb_by_aronnet(t_stack **a, t_stack **b)
{
	int	med;

	med = (lstsize(*a) + lstsize(*b)) / 2;
	while (lstsize(*b) < med)
	{
		if ((*a)->index <= med)
			pb(a, b);
		else
			ra(a);
	}
}

void	algo(t_stack **a, t_stack **b)
{
	int	best_pos;
	int	r_a_count;

	if (already_sort(*a))
		return ;
	else if (lstsize(*a) > 100)
		pb_by_aronnet(a, b);
	while (lstsize(*a) > 5)
		pb(a, b);
	homemade_sort(a, b);
	while (*b != NULL)
	{
		best_pos = choose_best(*a, *b);
		sort_stack(a, b, best_pos);
		pa(b, a);
	}
	r_a_count = count_rotation_b(*a, find_min(*a));
	mini_sort_stack(a, b, r_a_count, 0);
}
