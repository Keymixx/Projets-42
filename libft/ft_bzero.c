/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:19:02 by carl              #+#    #+#             */
/*   Updated: 2025/08/21 18:27:00 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *ptr, size_t n)
{
    size_t i = 0;
    unsigned char *p = (unsigned char*) ptr;
    
    while (i < n)
    {
        p[i] = '\0';
        i++;
    }
}
// int main(void)
// {
//     char a[] = "Prout";
//     printf("%s\n",a);
//     ft_bzero(a +2, sizeof(char) * 3);
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
//     ft_bzero(b, sizeof(b[0]) * 3);
//     while (i < 5)
//     {
//         printf("%d ",b[i]);
//         i++;
//     }
//     printf("\n");

//     printf("\n");
    
//     char c[] = "Prout";
//     printf("%s\n",c);
//     bzero(c + 2, sizeof(char) * 3);
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
//     bzero(d, sizeof(d[0]) * 3);
//     while (i < 5)
//     {
//         printf("%d ",d[i]);
//         i++;
//     }
//     printf("\n");
// }