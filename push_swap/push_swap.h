/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:48:53 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/10 02:29:37 by caaubert         ###   ########.fr       */
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

int is_valid_int(const char *num);
bool check_string(char *argv);
bool check_params(int argc,char *argv[]);
t_stack	*lstnew(int num, int index);
t_stack	*lstlast(t_stack *lst);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
t_stack *build_stack(int count, char *params[]);
void sa(t_stack **stack);
void sb(t_stack **stack);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a,t_stack **stack_b);
void pb(t_stack **stack_b,t_stack **stack_a);
void ra(t_stack **stack);
void rra(t_stack **stack);
t_stack	*lstlast_last(t_stack *lst);




#endif