/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:52:47 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/26 02:09:21 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb <= 9)
		count += ft_putchar(nb + 48);
	else
	{
		count += ft_putnbr_unsigned(nb / 10);
		count += ft_putchar(nb % 10 + 48);
	}
	return (count);
}

int	ft_putnbr_hex(uintptr_t nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_hex(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_putstr_null(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	else
		return (ft_putstr(str));
}

int	ft_puthex(char c, uintptr_t nbr)
{
	char	*base;
	int		count;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = ft_putnbr_hex(nbr, base);
	return (count);
}

int	ft_puthex_null(char c, void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_puthex(c, (uintptr_t)ptr);
	return (count);
}
