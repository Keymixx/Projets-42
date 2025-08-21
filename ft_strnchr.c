/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:48:14 by carl              #+#    #+#             */
/*   Updated: 2025/08/19 18:47:53 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnchr(char *str, char c , int len)
{
    int i = 0;

    while (str[i] && len > i)
    {
        if (str[i] == c)
            return (&str[i]);
        i++;
    }
    return(NULL);
}
int main(int argc, char *argv[])
{
    printf("%s\n",ft_strnchr(argv[1],argv[2][0],ft_atoi(argv[3])));
}