/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:01:57 by carl              #+#    #+#             */
/*   Updated: 2025/08/21 19:03:35 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy (void *dest, void *src, size_t size)
{
    int i = 0;
    unsigned char *p = (unsigned char*) ptr;
    
    while (i < n)
    {
        p[i] = val;
        i++;
    }
    return (ptr);
}

// int main(void)
// {
//     char a[] = "Prout";
//     printf("%s\n",a);
//     ft_memset(a, 'd', sizeof(char) * 5);
//     printf("%s\n",a);
    
//     int b[] = {13, 45 ,5765 ,654 ,0};
//     int i = 0;
//     while (i < 5)
//     {
//         printf("%d ",b[i]);
//         i++;
//     }
//     printf("\n");

//     i = 0;
//     ft_memset(b, 442, sizeof(b[0]) * 5);
//     while (i < 5)
//     {
//         printf("%d ",b[i]);
//         i++;
//     }
//     printf("\n");

//     printf("\n");
    
//     char c[] = "Prout";
//     printf("%s\n",c);
//     memset(c, 'd', sizeof(char) * 5);
//     printf("%s\n",c);
    
//     int d[] = {13, 45 ,5765 ,654 ,0};
//     i = 0;
//     while (i < 5)
//     {
//         printf("%d ",d[i]);
//         i++;
//     }
//     printf("\n");

//     i = 0;
//     memset(d, 442, sizeof(d[0]) * 5);
//     while (i < 5)
//     {
//         printf("%d ",d[i]);
//         i++;
//     }
//     printf("\n");
// }
