/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:35:27 by carl              #+#    #+#             */
/*   Updated: 2025/08/19 16:57:20 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(char *str)
{
    int i = 0;
    int total = 0;
    int sign = 1;
    
    while (!ft_isdigit(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        total = total * 10 + (str[i] - 48);
        i++;
    }
    return (total * sign);   
}
