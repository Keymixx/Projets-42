/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:28:56 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/21 00:36:42 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



int	ft_wordlen(char const*s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

int	ft_count_words(char const*s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s[i] != c)
		words++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (!s[i])
				return (words);
			words++;
		}
		i++;
	}
	return (words);
}

char	*ft_split_strdup(const char *str, char c)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_wordlen(str, c) + 1;
	dup = malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i] && str[i] != c)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void ft_freesplit(char **split, int n)
{
	int	i;

	i = 0;
	while (i <= n)
		free (split[i++]);
	free (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		size = ft_wordlen(&s[i], c);
		split[j] = malloc(sizeof(char *) * size + 1);
		if (!split[j])
		{
			ft_freesplit(split, j);
			return (NULL);
		}
		split[j++] = ft_split_strdup(&s[i], c);
	}
	split[j] = NULL;
	return (split);
}

// int main(void)
// {
// 	char str[] = "***Couco*Alall*Proutou*twtetq*df**f*ffff***";
// 	int i = 0;
// 	char **split = ft_split(str,'*');
// 	while (i < ft_count_words(str,'*'))
// 	{
// 		printf("%s\n",split[i]);
// 		i++;
// 	}
// }