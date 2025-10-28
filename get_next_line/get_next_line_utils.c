/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:03:17 by carl              #+#    #+#             */
/*   Updated: 2025/10/28 02:44:51 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int     ft_strlen(const char *str)
{
    int i;
    
    if (!str)
        return(0);
    i = 0;
    while(str[i])
        i++;
    return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(str) + 1;
	dup = malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
		dup[i] = str[i++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		i;
	int		j;	

	i = 0;
	j = 0;
    if (s1 == NULL)
        return (join = ft_strdup(s2));
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	join = malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	while (s1[i])
		join[i] = s1[i++];
	while (s2[j])
		join[i + j] = s2[j++];
	join[i + j] = '\0';
    i = 0;
    free(s1);
	return (join);
}