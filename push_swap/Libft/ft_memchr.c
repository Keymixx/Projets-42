/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:17:03 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:26:19 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buf;
	unsigned char	cc;
	size_t			i;

	i = 0;
	buf = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (buf[i] == cc)
			return ((void *)&buf[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str1[] = "Salut ca va ?";
// 	void * str2 = ft_memchr(str1, 'c', 12);
// 	void * str3 = ft_memchr(str2, 'c', 12);
// 	printf("%s \n",(char *)str1);
// 	printf("%s \n",(char *)str2);
// 	printf("%s \n",(char *)str3);
// }