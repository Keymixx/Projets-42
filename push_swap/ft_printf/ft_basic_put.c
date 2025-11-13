/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 00:55:56 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/26 02:08:27 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
		count += ft_putchar(str[i++]);
	return (count);
}

int	ft_putnbr(int nb)
{
	unsigned int	n;
	int				count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		n = nb * -1;
	}
	else
		n = nb;
	if (n <= 9)
		count += ft_putchar(n + 48);
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + 48);
	}
	return (count);
}
