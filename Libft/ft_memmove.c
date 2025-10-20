/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:26:05 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/20 18:33:25 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char	*dest;
	char	*src;
	size_t	i;

	if(destination == NULL && source == NULL)
		return (NULL);
	src = (char *)source;
	dest = (char *)destination;
	i = 0;
	if (dest <= src)
	{
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (size--)
		{
			dest[size] = src[size];
		}
	}
	return (dest);
}

// int main(void)
// {
// 	char str1[] = "*****";
// 	char str2[] = "123";
// 	char str3[] = "*****";
// 	char str4[] = "123";
// 	void *cpy1 = memmove(str1,str2,sizeof(char) * 4);
// 	void *cpy2 = ft_memmove(str3,str4,sizeof(char) * 4);
// 	printf("Real = %s \n",(char *)cpy1);
// 	printf("Mine = %s \n",(char *)cpy2);
// }