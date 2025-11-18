/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:03:17 by carl              #+#    #+#             */
/*   Updated: 2025/11/18 01:16:57 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		i;
	int		j;	

	i = 0;
	j = 0;
	len = (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1;
	join = malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	free(s1);
	return (join);
}
