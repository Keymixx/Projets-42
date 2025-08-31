/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:20:07 by carl              #+#    #+#             */
/*   Updated: 2025/08/31 18:28:33 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp (const void *ptr1, const void *ptr2, size_t size)
{
    size_t i = 0;
    unsigned char *p1 = (unsigned char *) ptr1;
    unsigned char *p2 = (unsigned char *) ptr2;
    
    while (i < size)
    {
        if(p1[i] != p2[i])
            return (p1[i] - p2[i]);
        i++;
    }
    return (0);
}