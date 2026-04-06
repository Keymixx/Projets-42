/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:17:03 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/17 16:43:34 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int c, size_t count)
{
	unsigned char	*buf;
	unsigned char	cc;
	size_t			i;

	i = 0;
	buf = (unsigned char *)buffer;
	cc = (unsigned char)c;
	while (i < count )
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