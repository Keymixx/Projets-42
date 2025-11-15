/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:48:53 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 21:00:46 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack
{
	int	num;
	int index;	
	struct s_stack *next;
}	t_stack;

#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool is_valid_int(const char *num);
bool check_string(char *argv);
bool check_params(int argc,char *argv[]);
t_stack	*lstnew(int num, int index);
t_stack	*lstlast(t_stack *lst);
int		lstsize(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
t_stack *build_stack(int count, char *params[]);
void sa(t_stack **stack);
void sb(t_stack **stack);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **b,t_stack **a);
void pb(t_stack **stack_a,t_stack **stack_b);
void ra(t_stack **stack);
void rb(t_stack **stack);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **stack);
void rrb(t_stack **stack);
void rrr(t_stack **a, t_stack **b);
t_stack	*lstlast_last(t_stack *lst);
int calcul_cost(t_stack *a, t_stack *b, int pos_b);
int find_min(t_stack *a);
int find_index(t_stack *b, int pos_b);
int find_target(t_stack *a, int index);
void algo(t_stack **a, t_stack **b);
int choose_best(t_stack *a, t_stack *b);
void sort_stack(t_stack **a, t_stack **b, int pos_b);
void sort_three(t_stack **a);
void homemade_sort(t_stack **a, t_stack **b);
bool already_sort(t_stack *a);



#endif