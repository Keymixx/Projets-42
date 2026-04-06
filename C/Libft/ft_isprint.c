/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:01:56 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/20 18:26:17 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

// int main(void)
// {
//     printf("%d ... %d\n",ft_isprint('a'),isprint('a'));
//     printf("%d ... %d\n",ft_isprint('A'),isprint('A'));
//     printf("%d ... %d\n",ft_isprint('/'),isprint('/'));
//     printf("%d ... %d\n",ft_isprint('9'),isprint('9'));
//     printf("%d ... %d\n",ft_isprint('%'),isprint('%'));
//     printf("%d ... %d\n",ft_isprint(127),isprint(127));
//     printf("%d ... %d\n",ft_isprint(5),isprint(5));
//     printf("%d ... %d\n",ft_isprint(32),isprint(32));
// 	printf("%d ... %d\n",ft_isprint(128),isprint(128));
// }