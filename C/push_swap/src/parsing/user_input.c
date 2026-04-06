/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:07:16 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/17 23:25:33 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_int(const char *num)
{
	long long	tot;
	int			i;
	int			sign;

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
	while (ft_isdigit(num[i]))
		tot = tot * 10 + (num[i++] - '0');
	tot = tot * sign;
	if (tot > INT_MAX || tot < INT_MIN)
		return (false);
	return (true);
}

bool	check_string(char *argv)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (!argv)
		return (false);
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) || argv[i] == '+' || argv[i] == '-')
		{
			if (!is_valid_int(&argv[i]))
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

bool	check_params(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_digit(argv[i]))
			return (false);
		if (!is_valid_int(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
