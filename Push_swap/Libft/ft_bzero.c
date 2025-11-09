/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:04:18 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/24 16:43:54 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int main(void)
// {
	// char a[] = "Coucou !";
	// printf("%s\n",a);
	// ft_bzero(a,1);
	// printf("%s\n",&a[0]);
// 	printf("\n");
// 	char b[] = "123456";
// 	printf("%s\n",b);
// 	ft_bzero(b,5);
// 	printf("%s\n",b);
// 	printf("\n");
// 	char c[] = "Coucou !";
// 	printf("%s\n",c);
// 	bzero(c,3);
// 	printf("%s\n",c);

// 	printf("\n");
// 	char d[] = "123456";
// 	printf("%s\n",d);
// 	bzero(d,5);
// 	printf("%s\n",d);
// }