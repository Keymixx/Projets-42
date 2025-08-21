/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:41:13 by carl              #+#    #+#             */
/*   Updated: 2025/08/21 18:20:45 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset (void *ptr, int val, int n)
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
