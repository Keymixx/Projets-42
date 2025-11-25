/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:28:56 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/21 23:50:36 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const*s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] == c)
			i++;
	}
	return (words);
}

static char	*ft_split_strdup(const char *str, int size)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_freesplit(char **split, int n)
{
	while (n >= 0)
		free (split[n--]);
	free (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] && ft_count_words(s, c) > 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			split[j] = ft_split_strdup(&s[i], ft_wordlen(&s[i], c));
			if (!split[j++])
				return (ft_freesplit(split, j), NULL);
			i += ft_wordlen(&s[i], c);
		}
	}
	return (split[j] = NULL, split);
}

// int main(void)
// {
// 	char str[] = "***Couco*Alall*Proutou*twtetq*df**f*ffff***";
// 	int i = 0;
// 	char **split = ft_split(str,' ');
// 	while (i < ft_count_words(str,' '))
// 	{
// 		printf("%s\n",split[i]);
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }