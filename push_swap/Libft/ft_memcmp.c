/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:57:28 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:26:21 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (i < n)
	{
		if (buf1[i] != buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (buf1[i] - buf2[i]);
}
// int main(void)
// {
// 	printf("Mine : %d\n",ft_memcmp("QVGFDFS","ABFFASF", 50));
// 	printf("Mine : %d\n",ft_memcmp("    $!@","LCLCLLCC", 50));
// 	printf("Real : %d \n",memcmp("QVGFDFS","ABFFASF", 50));
// 	printf("Real : %d \n",memcmp("   $!@","LCLCLLCC", 50));
// }