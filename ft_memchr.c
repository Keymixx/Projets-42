/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:45:35 by carl              #+#    #+#             */
/*   Updated: 2025/08/31 18:02:04 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(void *src, int c ,size_t size)
{
    size_t i = 0;
    unsigned char *s = (unsigned char*) src;

    while (i < size)
    {
        if (c == s[i])
            return (&s[i]);
        i++;
    }
    return (NULL);
}

int main(int argc, char *argv[])
{
    char *a = argv[1];
    char b = argv[2][0];
    char *c = ft_memchr (a,b,ft_atoi(argv[3]));
    printf("%s\n",c);
}
