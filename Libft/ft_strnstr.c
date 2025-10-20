/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:22:02 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/20 17:49:34 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str2[0])
		return((char *)str1);
	while (str1[i] && len > i)
	{
		j = 0;
		while (str1[i + j] == str2[j] && len > i + j) 
		{
			if (str2[j + 1] == '\0')
				return ((char *)&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int main (void)
// {
// 	char string1[] = "The quick brown dog jumps over the lazy fox";
// 	char string2[] = "jumps";
// 	char string3[] = "The quick brown dog jumps over the lazy fox";
// 	char string4[] = "jumps";
// 	int	i = 0;
// 	while (string1[i])
// 	{
// 		printf("%s (i = %d)\n",ft_strnstr(string1,string2,i),i);
// 		printf("%s (i = %d)\n",strnstr(string3,string4,i),i);
// 		printf("\n");
// 		i++;
// 	}
// }