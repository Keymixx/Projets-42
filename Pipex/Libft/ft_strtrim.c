/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:04:27 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/21 23:34:23 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s1[0])
		return (ft_strdup(""));
	if (!set[0])
		return (ft_strdup(s1));
	k = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_isset(s1[i], set))
		i++;
	while (ft_isset(s1[j], set) && j >= i)
		j--;
	if (j == i)
		ft_strdup("");
	trim = malloc (sizeof(char) * ((j - i) + 2));
	if (!trim)
		return (NULL);
	while (i <= j)
		trim[k++] = s1[i++];
	trim[k] = '\0';
	return (trim);
}
// int main(void)
// {
// 	char str[] = "/*-/*-/*--|abc--/*Coucou|-**---*//*-/-";
// 	char set[] = "/*2138-";
// 	printf("%s\n",ft_strtrim(str,set));
// }