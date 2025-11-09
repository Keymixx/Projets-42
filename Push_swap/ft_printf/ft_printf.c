/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:41:03 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/26 02:04:09 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkchar(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_null(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_puthex_null('x', (va_arg(args, void *))));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'X' || c == 'x')
		return (ft_puthex(c, (va_arg(args, unsigned int))));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			i++;
			count += ft_checkchar(form[i++], args);
		}
		if (form[i] && form[i] != '%')
			count += ft_putchar(form[i++]);
	}
	va_end(args);
	return (count);
}
