/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:48:14 by carl              #+#    #+#             */
/*   Updated: 2025/08/19 18:37:01 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(char *big, char *little , int len)
{
    int i = 0;

    if(!little[i])
        return (big);
    
    while (big[i] && len > i)
    {
        int j = 0;
        while (big[i + j] == little[j] && len > (i + j) && big[i + j])
        {
            if (!little[j + 1])
                return (&big[i]);
            j++;
        }
        i++;
    }
    return(NULL);
}
int main(int argc, char *argv[])
{
    printf("%s\n",ft_strnstr(argv[1],argv[2],ft_atoi(argv[3])));
}