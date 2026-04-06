/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:54:07 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/13 15:01:35 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int main(void)
// {
//     printf("%d ... %d\n",ft_isascii('a'),isascii('a'));
//     printf("%d ... %d\n",ft_isascii('A'),isascii('A'));
//     printf("%d ... %d\n",ft_isascii('/'),isascii('/'));
//     printf("%d ... %d\n",ft_isascii('9'),isascii('9'));
//     printf("%d ... %d\n",ft_isascii('%'),isascii('%'));
//     printf("%d ... %d\n",ft_isascii(127),isascii(127));
//     printf("%d ... %d\n",ft_isascii(5),isascii(5));
//     printf("%d ... %d\n",ft_isascii(32),isascii(32));
// 	printf("%d ... %d\n",ft_isascii(128),isascii(128));
// }