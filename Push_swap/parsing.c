/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:07:16 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/09 03:45:14 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_int(const char *num)
{
	long long		tot;
	int				i;
	int				sign;

	i = 0;
	tot = 0;
	sign = 1;

	if (num[i] == '+')
		i++;
	else if (num[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (isdigit(num[i]))
		tot = tot * 10 + (num[i++] - '0');
	tot = tot * sign;
	if (tot > INT_MAX || tot < INT_MIN)
		return (0);
	return (tot);
}

bool check_string(char *argv)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	if(!argv)
		return (false);
	while (argv[i])
	{
		if (isdigit(argv[i]) || argv[i] == '+' || argv[i] == '-')
		{
			if(!is_valid_int(&argv[i]))
				return (false);
			i += ft_intlen(ft_atoi(&argv[i]));
			num++;
		}
		else if (argv[i] == ' ')
			i++; 
		else
			return (false);
	}
	if (num == 0)
		return (false);
	return (true);
} 

bool check_params(int argc,char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!check_string(argv[i]))
			return (false);
		i++;	
	}
	return (true);
}

