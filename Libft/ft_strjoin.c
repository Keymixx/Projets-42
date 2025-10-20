/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:33:36 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/14 22:27:00 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;
	int		i;
	int		j;	

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	join = malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

// int main(void)
// {
// 	char str1[] = "coucou ca va ?";
// 	char str2[] = " oui super.";
// 	printf("%s\n",ft_strjoin(str1,str2));
// }