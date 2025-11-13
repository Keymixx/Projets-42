/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:26:05 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/21 23:41:35 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (d <= s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (d);
}

// int main(void)
// {
// 	char str1[] = "*****";
// 	char str2[] = "123";
// 	char str3[] = "*****";
// 	char str4[] = "123";
// 	void *cpy1 = memmove(str1,str2,nof(char) * 4);
// 	void *cpy2 = ft_memmove(str3,str4,nof(char) * 4);
// 	printf("Real = %s \n",(char *)cpy1);
// 	printf("Mine = %s \n",(char *)cpy2);
// }