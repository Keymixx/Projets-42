/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:57:28 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/20 17:11:54 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buffer1, const void *buffer2, size_t count)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	buf1 = (unsigned char *)buffer1;
	buf2 = (unsigned char *)buffer2;
	i = 0;
	if (!count)
		return 0;
	while (i < count)
	{
		if (buf1[i] != buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	if (i == count)
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