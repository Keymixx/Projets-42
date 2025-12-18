/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:38:50 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:26:27 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		d[i] = c;
		i++;
	}
	return ((void *)d);
}

// int main(void)
// {
// 	char a[] = "Coucou !";
// 	printf("%s \n",a);
// 	ft_memset(a,'*',14);
// 	printf("%s \n",a);
// 	printf("\n");
// 	char b[] = "123456";
// 	printf("%s \n",b);
// 	ft_memset(b,'*',5);
// 	printf("%s \n",b);
// 	printf("\n");

// 	char c[] = "Coucou !";
// 	printf("%s \n",c);
// 	memset(c,'*',14);
// 	printf("%s \n",c);
//  	printf("\n");

// 	char d[] = "123456";
// 	printf("%s \n",d);
// 	memset(d,'*',5);
// 	printf("%s \n",d);
// }