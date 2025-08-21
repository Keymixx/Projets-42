/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:48:14 by carl              #+#    #+#             */
/*   Updated: 2025/08/19 18:50:14 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(char *str, char c)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == c)
            return (&str[i]);
        i++;
    }
    return(NULL);
}
int main(int argc, char *argv[])
{
    printf("%s\n",ft_strchr(argv[1],argv[2][0]));
}