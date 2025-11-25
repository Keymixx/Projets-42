/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:30:19 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/25 22:04:26 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// int main(void)
// {
//     printf("%ld ... %ld\n",ft_strlen("cpicsd"),strlen("cpicsd"));
//     printf("%ld ... %ld\n",ft_strlen("cp"),strlen("cp"));
//     printf("%ld ... %ld\n",ft_strlen("4194 89"),strlen("4194 89"));
//     printf("%ld ... %ld\n",ft_strlen(""),strlen(""));
//     printf("%ld ... %ld\n",ft_strlen(" d "),strlen(" d "));
//     printf("%ld ... %ld\n",ft_strlen("7777"),strlen("7777"));
//     printf("%ld ... %ld\n",ft_strlen("123"),strlen("123"));
//     printf("%ld ... %ld\n",ft_strlen("           "),strlen("           "));
// }