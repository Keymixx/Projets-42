/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:28:06 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:25:56 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char			*array;
	int				i;
	unsigned int	num;

	if (n == 0)
		return (ft_strdup("0"));
	if (ft_isneg(n))
		num = -n;
	else
		num = n;
	array = malloc(ft_intlen(n) * sizeof(char) + ft_isneg(n) + 1);
	if (!array)
		return (NULL);
	i = 0;
	while (i < ft_intlen(n))
	{
		array[i++] = ((num % 10) + '0');
		num = num / 10;
	}
	if (ft_isneg(n))
		array[i++] = '-';
	array[i] = '\0';
	return (ft_swap(array), array);
}
