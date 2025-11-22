/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:26:46 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/21 23:10:34 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
// int main(void)
// {
// 	char str1[] = "*****";
// 	char str2[] = "123456789";
// 	char str3[] = "*****";
// 	char str4[] = "123456789";
// 	int a = ft_strlcpy(str1,str2,6);
// 	int b = strlcpy(str3,str4,6);
// 	printf("Mine str : %s .... Mine return : %d \n",str1,a);
// 	printf("Real str : %s .... Real return : %d \n",str3,b);
// }